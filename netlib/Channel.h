/*************************************************************************
	> File Name: Channel.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 12时18分05秒
 ************************************************************************/

#ifndef _CHANNEL_H
#define _CHANNEL_H

#include "Timestamp.h"
#include "EventLoop.h"
#include <functional>
#include <memory>
#include "callback.h"
class Channel
{
public:
    typedef std::function<void()> EventCallback;
    typedef std::function<void(Timestamp)> ReadEventCallback;

    /*构造函数*/
   Channel(EventLoop* loop, int fd)
    :loop_(loop),
    fd_(fd),
    events_(0),
    revents_(0)
{
}

~Channel()
{
}

/*设置事件类型或获得事件类型*/
void enableReading() { events_ |= kReadEvent;  }
void enableWriting() { events_ |= kWriteEvent; }
void disableReading() { events_ &= ~kReadEvent; }
void disableWriting() { events_ &= ~kWriteEvent; }
bool isReading() const { return events_ & kReadEvent; }
bool isWriting() const { return events_ & kWriteEvent; }
    
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

    EventLoop* loop_;    //事件所在循环
    const int fd_;       //监听的fd
    int events_;         //关注的事件
    int revents_;        //当前活跃事件

    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;

};

#endif
