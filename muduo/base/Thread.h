/*************************************************************************
	> File Name: Thread.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月22日 星期六 20时02分17秒
 ************************************************************************/

#ifndef MUDUO_BASE_THREAD_H
#define MUDUO_BASE_THREAD_H

#include <muduo/base/Atomic.h>
#include <muduo/base/Types.h>

#include <boost/function,hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <pthread.h>

namespace muduo
{
    class Thread : boost::noncopyable
    {
    public:
        typdef boost::function<void ()> ThreadFunc;
        explicit Thread(ThreadFunc&&, const string& name = string());
        ~Thread();
        void start();
        int join();
        bool started() const {return started_;}
        pid_t tid const { return *tid_; }
        const string& name() const { return name_; }
        static int numCreated() { return numCreate_.get(); }

    private:
        void setDefaultName();

        bool         started_;
        bool         joined_;
        pthread_t    pthreadId_;
        boost::shared_ptr<pid_t>  tid_;
        ThreadFunc  func_;
        string      name_;

        static AtomicInt32  numCreated_;
    };

#endif
