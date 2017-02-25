/*************************************************************************
	> File Name: Acceptor.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 14时25分50秒
 ************************************************************************/

#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H


#include <iostream>
#include <functional>
#include "Socket.h"
#include "Channel.h"
#include "event_loop.h"
#include "callback.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "Eventloop_Threadpool.h"
#include <unistd.h>
#include <string>
#include <assert.h>

class Acceptor
{
public:

    void connectionhandle(int connfd, struct sockaddr_in addr)
    {
        int fd = loopThreadPoolPtr_->getNextLoop();  //得到connfd将要去的循环的fd
        std::cout << "Acceptor.h文件：为connfd分配loop, loop_id 为" << fd << std::endl;
        ssize_t  buff = static_cast<ssize_t>(connfd);
        ssize_t ret = write(fd, &buff, sizeof(buff));   //送它去
        assert(ret == sizeof(buff));
    }


/*初始化loop池,创建监听套接字，初始化事件分发器*/
    Acceptor(std::string ip, int port, int loopNumber)
    :accpetSocket_(::socket(PF_INET,SOCK_STREAM, 0)),
    loopThreadPoolPtr_(std::make_shared<LoopThreadPool>(loopNumber))
    {
        accpetSocket_.bindAddress(ip, port);
        accpetSocket_.setReusePort(true);
        accpetSocket_.listen();
    }

    /*析构*/
    ~Acceptor()
    {
        accpetSocket_.close();
    }


/*loop池开启，接收新连接*/
    void start(void)
    {
        loopThreadPoolPtr_->setMessageCallback(messageCallback_);   //设置消息回调
        loopThreadPoolPtr_->setCloseCallback(closeCallback_);
        loopThreadPoolPtr_->setWriteCompleteCallback(writeCompleteCallback_);

        loopThreadPoolPtr_->start();
        struct sockaddr_in clientAddress;   //保存客户端地址
 
        while(1)
        {
        int connfd = accpetSocket_.accept(&clientAddress); //接收连接
        if(connfd > 0)
        {
            std::cout << "Acceptor.h文件: get a new connection, connfd = " << connfd << std::endl;
            connectionhandle(connfd, clientAddress);    //
        }
        }
    }   

    void setMessageCallback(MessageCallback cb)
    {
        messageCallback_ = cb;
    }

    Socket getSocket()
    {
        return accpetSocket_;
    }

private:

    std::shared_ptr<LoopThreadPool> loopThreadPoolPtr_;
    Socket    accpetSocket_;                               //监听socket
    NewConnectionCallback newConnectionCallback_;
    MessageCallback messageCallback_;
    CloseCallback   closeCallback_;
    WriteCompleteCallback writeCompleteCallback_;
};

#endif
