/*************************************************************************
	> File Name: EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 18时29分28秒
 ************************************************************************/

#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H


#include <vector>
#include "Epoller.h"
#include <functional>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>
#include "Channel.h"



class EventLoop
{
public:
    typedef std::function<void()> Functor;

    EventLoop();
    ~EventLoop();

    void loop();   //开始循环

    void quit();  //退出循环

    void runInLoop(const Functor& cb);   //本循环执行回调

    void queueInLoop(const Functor& cb);  //不在当前循环，加入队列

    void wakeup();  //唤醒I/O循环

    void updateChannel(Channel* channel);  //更新事件分发表

    void removeChannel(Channel* channel);  //移除事件分发器

    bool assertInLoopThread();   //判断是否在当前线程

    void doPendingFunctors();

    void handleRead();

private:
    bool looping_;
    bool quit_;

    pid_t threadId_;                /*当前循环所属线程ID*/
    Timestamp pollReturnTime_;      /*poll返回时间*/

    boost::scoped_ptr<Epoller> poller_;    /*当前循环的poll*/
    
    int wakeupFd_;     /*唤醒eventfd*/
    boost::scoped_ptr<Channel> wakeupChannel_;  /*唤醒eventfd对应的Channel*/  

    typedef std::vector<Channel*> ChannelList;
    ChannelList activeChannels_;      /*活跃事件表*/

    Channel* currentActiveChannel_;   /*当前正在处理的活跃事件*/

    std::vector<Functor> pendingFunctors_;  /*存储别的线程的活跃任务一会处理*/
};
#endif
