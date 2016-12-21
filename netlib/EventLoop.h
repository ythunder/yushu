/*************************************************************************
	> File Name: EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 18时29分28秒
 ************************************************************************/

#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include <memory>
#include <vector>
#include "Epoller.h"
#include <functional>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>
#include "Channel.h"

class Channel;
class Epoller;

class EventLoop
{
private:

    bool looping_;
    bool quit_;

    pid_t threadId_;                /*当前循环所属线程ID*/

    std::shared_ptr<Epoller> poller_;    /*当前循环的poll*/
    
    int eventfd_;     /*唤醒eventfd*/
    Channel* wakeupChannel_;  /*唤醒eventfd对应的Channel*/  

    /*
    typedef std::vector<Channel*> ChannelList;
    ChannelList activeChannels_;      //活跃事件表

    Channel* currentActiveChannel_;   //当前正在处理的活跃事件
*/


public:

    EventLoop(int eventfd);
    ~EventLoop();

    void loop();   //开始循环

    void quit();  //退出循环

    

    //void updateChannel(Channel* channel);  //更新事件分发表

    void removeChannel(Channel* channel);  //移除事件分发器

    bool assertInLoopThread();   //判断是否在当前线程


    void handleRead();

    int getloop_eventfd()
    {
        return eventfd_;
    }

};

#endif
