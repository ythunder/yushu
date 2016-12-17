/*************************************************************************
	> File Name: Channel.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 12时18分05秒
 ************************************************************************/

#ifndef CHANNEL_H
#define CHANNEL_H

#include "Timestamp.h"
#include "EventLoop.h"
#include <functional>
#include <memory>
#include <poll.h>
#include "callback.h"

class EventLoop;

class Channel
{
public:
    typedef std::function<void()> EventCallback;
    typedef std::function<void()> ReadEventCallback;

    /*构造函数*/
   Channel(int eventfd, int fd)
    :loopfd_(eventfd),
    fd_(fd),
    events_(0),
    revents_(0)
{
}

    ~Channel()
{
}


int ownerLoop()
{
    return loopfd_;    
}


/*设置事件处理函数*/
void handleEvent()
{
    if(revents_ &  POLLIN)
    {
        if(readCallback_) readCallback_();
    }
    else if(revents_ & POLLOUT)
    {
        if(writeCallback_) writeCallback_();
    }
    else if(revents_ & POLLERR)
    {
        if(errorCallback_) errorCallback_();
    }
}
    

    
/*设置读、写、关闭和错误回调*/
void setReadCallback(const ReadEventCallback& cb)
    { readCallback_ = cb; }
void setWriteCallback(const EventCallback& cb)
    { writeCallback_ = cb; }
void setCloseCallback(const EventCallback& cb)
    { closeCallback_ = cb; }
void setErrorCallback(const EventCallback& cb)
    { errorCallback_ = cb; }


    int fd()
    {
        return fd_;
    }

    int events()
    {
        return events_;
    }

    int revents()
    {
        return revents_;
    }


void set_revents(int revents)
{
    revents_ = revents;
}
private:
    /*三种事件类型的值定义*/
    static const int kNoneEvent;   
    static const int kReadEvent;
    static const int kWriteEvent;

    int loopfd_;    //事件所在循环
    const int fd_;       //监听的fd
    int events_;         //关注的事件
    int revents_;        //当前活跃事件

    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;

};
#endif
