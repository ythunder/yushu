/*************************************************************************
	> File Name: BlockingQueue.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月24日 星期一 00时39分27秒
 ************************************************************************/

#ifndef MUDUO_BASE_BLOCKINGQUEUE_H
#define MUDUO_BASE_BLOCKINGQUEUE_H

#include <boost/noncopyable.hpp>
#include <deque>
#include <assert.h>

namespace muduo
{
template<typename T>
class BlockingQueue : boost::noncopyable
{
public:
    BlockingQueue()
        :mutex_(),
        notEmpty_(mutex_),
        queue_()
    {  }

    void put(const T& x)
    {
        MutexLockGuard lock(mutex_);
            queue_.push_back(x);
        notEmpty_.notify();
    }

    #ifdef __GXX_EXPERIMENTAL_CXXOX_
    void put(T&& x)
    {
        MutexLockGuard lock(mutex_);
        queue.push_back(std::move(x));
        notEmpty_.notify();
    }
    #endif

    T take()
    {
        MutexLockGuard lock();
        while(queue_.empty())
        {
            notEmpty_.wait();
        }
        assert(!queue_.empty());
        #ifdef __GXX_EXPERIMENTAL_CXXOX_
        T front(std::move(queue_.front()));
        #else
        T front(queue_.front());
        #endif
        queue_.pop_front();
        return front;
        
    }

    size_t size() const
    {
        MutexLockGuard lock(mutex_);
        return queue_.size();
    }

private:
    MutexLock mutex_;
    Condition notEmpty_;
    std::deque queue_;    //双端队列
};
}
#endif
