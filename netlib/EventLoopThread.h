/*************************************************************************
	> File Name: EventLoopThread.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月18日 星期五 00时39分55秒
 ************************************************************************/

#ifndef _EVENTLOOPTHREAD_H
#define _EVENTLOOPTHREAD_H

#include "Condition.h"
#include "Mutex.h"
#include "Thread.h"
#include "EventLoop.h"
#include <functional>
#include <boost/bind.hpp>

class EventLoop;

class EventLoopThread
{
public:
    typedef std::function<void(EventLoop*)> ThreadInitCallback;

    EventLoopThread(const ThreadInitCallback& cb = ThreadInitCallback())
        :loop_(NULL),
        exiting_(false),
        thread_(boost::bind(&EventLoopThread::threadFunc,this)),
        mutex_(),
        cond_(mutex_),
        callback_(cb)
    {       
    }


    ~EventLoopThread()
    {
        exiting_ = true;
        if(loop_ != NULL)
        {
            loop_->quit();
            thread_.join();
        }
    }
    
    EventLoop* startLoop()
    {
        assert(!thread_.started());
        thread_.start();
        {
            MutexLockGuard lock(mutex_);
            while(loop_ == NULL)
            {
                cond_wait();
            }
        }
    }

private:

    void threadFunc()
    {
        EventLoop loop;
        if(callback_)
        {
            callback_(&loop);
        }
        {
            MutexLockGuard lock(mutex_);
            loop_ = &loop;
            cond_.notify();
        }
        loop.loop();
        loop_ = NULL;
    }

    EventLoop* loop_;
    bool exiting_;
    Thread thread_;
    MutexLock mutex_;
    Condition cond_;
    ThreadInitCallback callback_;
};
#endif
