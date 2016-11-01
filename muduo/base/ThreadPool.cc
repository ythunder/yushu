#include <muduo/base/ThreadPool.h>
#include <muduo/base/Exception.h>

#include <boost/bind.hpp>
#include <assert.h>
#include <stdio.h>

using namespace muduo;

ThreadPool::ThreadPool(const string& nameArg)
    :mutex_(),
    notEmpty_(mutex_),
    notFull_(mutex_),
    name_(nameArg),
    maxQueueSize_(0),
    running_(false)
{  }

ThreadPool::~ThreadPool()
{
    if(running_)
    {
        stop();
    }
}

void
Thread::stop()
{
    {
    MutexLockGuard lock(mutex_);
    running_ = false;
    notEmpty_.notifyAll();
    }
    for_each(threads_.begin(), 
            threads_.end(), 
             boost::bind(&muduo::Thread::join, _1));
}

void 
ThreadPool::start(int numThreads)
{
    assert(Threads_.empty());
    running_ = true;
    threads_.reserve(numThreads);
    for(int i=0; i<numThreads; ++i)
    {
        char id[32];
        snprintf(id, sizeof id, "%d", i+1);
        threads_.push_back(new muduo::Thread(
            boost::bind(&ThreadPool::runInThread, this), name_+id));
    threads_[i].start();
    }
    if(numThreads == 0 && threadInitCallback_)
    {
        threadInitCallback_();
    }
}


size_t ThreadPool::queueSize() const
{
    MutexLockGuard lock(mutex_);
    return queue_.size();
}

void ThreadPool::run(const Task& task)
{
    if(Threads_.empty())
    {
        task();
    }
    else
    {
        MutexLockGuard lock(mutex_);
        while(isFull())
        {
            notFull_.wait();
        }
        assert(!Full());
        queue_.push_back(task);
        notEmpty_.notifyAll();
    }
}


