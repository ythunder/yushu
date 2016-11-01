/*************************************************************************
	> File Name: ThreadPool.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月27日 星期四 01时07分54秒
 ************************************************************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>
#include <muduo/base/Thread.h>
#include <muduo/base/Types.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <deque>

class ThreadPool : boost::noncopyable
{
public:
    typedef boost::function<void()> Task;

    explicit ThreadPool(const string& nameArg = string("ThreadPool"));
    ~ThreadPool();

    void setMaxQueueSize(int maxSize)
    {
        maxQueueSize_ = maxSize;
    }

    void setThreadInitCallback(const Task& cb)
    {
        threadInitCallback_ = cb;
    }

    void start(int numThreads);

    void stop();

    const string& name() const
    {
        return name_;
    }

    size_t queueSize() const;

    void run(const Task& f);

    void run(Task& f);
    
private:
    bool isFull() const;
    void runInThread();
    Task take();

    mutable MutexLock mutex_;
    Condition notEmpty_;
    Condition notFull_;
    string name_;
    Task threadInitCallback_;
    boost::ptr_vector<muduo::Thread> threads_;
    std::deque<Task> queue_;
    size_t maxQueueSize_;
    bool running_;
};

#endif
