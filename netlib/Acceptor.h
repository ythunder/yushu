/*************************************************************************
	> File Name: Acceptor.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 14时25分50秒
 ************************************************************************/

#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H

#include <functional>
#include "Socket.h"
#include "Channel.h"
#include "EventLoop.h"

class Acceptor
{
public:
/*初始化loop,创建监听套接字，初始化事件分发器*/
    Acceptor(EventLoop *loop, char* ip, int port)
    :loop_(loop),
    accpetSocket_(::socket(PF_INET,SOCK_STREAM | , IPPROTO_TCP)),
    accpetSocket_.bindAddress(ip, port),
    acceptChannel_(loop, accpetSocket_.fd())
    {
        accpetSocket_.setReusePort(true);
        acceptChannel_.setReadCallback(
            boost::bind(&Acceptor::handleRead, this)
            );
    }

    /*析构*/
    ~Acceptor()
    {
    }

    /*设置新连接回调函数*/
    void setNewConnectionCallback(NewConnectionCallback& cb)
    {
        newConnectionCallback_ = cb;
    }

    /*监听*/
    void listen()
    {
        accpetSocket_.listen();
    }

    Socket getSocket()
    {
        return accpetSocket_;
    }
private:
    /*接受连接，调用连接成功回调函数*/
    void handleRead()
    {
        loop->assertInLoopThread();
        struct sockaddr_in peerAddr;   //存储客户端地址
        int connfd = accpetSocket_.accept(&peerAddr);  //接收连接
        if(connfd > 0)
        {
            if(newConnectionCallback_)
            {
                newConnectionCallback_(connfd, peerAddr);
            }
        }


    }

    EventLoop *loop_;
    Socket    accpetSocket_;
    Channel   acceptChannel_;
    NewConnectionCallback newConnectionCallback_;
};

#endif
