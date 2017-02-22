/*======================================================
    > File Name: eventLoop.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月19日 星期六 22时12分59秒
 =======================================================*/

#pragma once

#include "callback.h"
#include "objectPool.h"
#include <memory>
#include <functional>
#include "Channel.h"
#include <sys/epoll.h>
#include "Epoller.h"
#include "Connection.h"
#include <stdio.h>
#include <map>
#include <vector>

class Channel;
class Epoller;
class Connection;

class EventLoop
{
public:
    EventLoop(int eventFd);
    ~EventLoop();

    bool asserInLoopThread();
    
    void loop();

    void quit();

    void removeChannel(Channel* channel);

    void handleEventFdRead(void);
    void handleRead(int fd);
    void handleClose(int fd);

    int getloop_eventfd()
    {
        return eventfd_;
    }
    void setMessageCallback(MessageCallback cb)
    {
        messageCallback_ = cb;
    }
    void setCloseCallback(CloseCallback cb)
    {
        closeCallback_ = cb;
    }
    void setWriteCompleteCallback(WriteCompleteCallback cb)
    {
        writeCompleteCallback_ = cb;
    } 

private:
    typedef std::map<int,std::shared_ptr<Connection>> ConnectionMap;

    bool looping_;
    bool quit_;

    pid_t threadId_;

    int eventfd_;  //用于主loop向其他loop传递新连接的文件描述符
    std::shared_ptr<Epoller> poller_;  //所拥有的epoll循环
    struct epoll_event events_[1024];  //获取epoll的就绪事件
    MessageCallback messageCallback_;    //消息回调
    CloseCallback closeCallback_;  //关闭回调
    ObjectPool<Connection> objectPool_; //连接对象池
    WriteCompleteCallback writeCompleteCallback_;
    ConnectionMap connectionMap_;
};
