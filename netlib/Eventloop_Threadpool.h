/*************************************************************************
	> File Name: Eventloop_Threadpool.h
	> Author: 
	> Mail: 
	> Created Tim: 2016年12月14日 星期三 16时38分35秒
 ************************************************************************/

#ifndef _EVENTLOOP_THREADPOOL_H
#define _EVENTLOOP_THREADPOOL_H

#include <map>
#include <vector>
#include <thread>
#include <memory>
#include "callback.h"
#include <iostream>
#include <sys/eventfd.h>


class LoopThreadPool
{
public:
    LoopThreadPool(int number);

    ~LoopThreadPool();

    int getNextLoop();

    void start();

    int createEventFd();

    void setMessageCallback(MessageCallback cb)
    {
        messageCallback_ = cb;
    }

    const MessageCallback getMessageCallback()
    {
        return messageCallback_;
    }

    void setCloseCallback(CloseCallback cb)
    {
        closeCallback_ = cb;
    }
    
    const CloseCallback getCloseCallback()
    {
        return closeCallback_;
    }

    void setWriteCompleteCallback(WriteCompleteCallback cb)
    {
        writeCompleteCallback_ = cb;
    }
    
    const WriteCompleteCallback getWriteCompleteCallback()
    {
        return writeCompleteCallback_;
    }


    int loopNumber_;   //loop总数
    int next_;     //下一个loop代表的整数
    std::map<int,int> fdMap_;  //保存整数与每个loop的eventfd的映射
    std::vector< std::shared_ptr<std::thread> > threadVector_;   //保存开启的loop线程的智能指针的集合
    MessageCallback messageCallback_;
    CloseCallback closeCallback_;
    WriteCompleteCallback writeCompleteCallback_;
};

#endif
