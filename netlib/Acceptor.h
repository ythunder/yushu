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
#include "EventLoop.h"
#include "callback.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "Eventloop_Threadpool.h"

class Acceptor
{
public:

    void connectionhandle(int connfd, struct sockaddr_in addr)
    {
        int fd = loopThreadPoolPtr_->getNextLoop();  //得到connfd将要去的循环的fd
        std::cout << "get loop evetfd " << fd << std::endl;
        int buff = connfd;
        int ret = write(fd, &buff, sizeof(buff));   //送它去
        assert(ret == sizeof(buff));
    }


/*初始化loop池,创建监听套接字，初始化事件分发器*/
   Acceptor(char* ip, int port, int loopNumber)
    :accpetSocket_(::socket(PF_INET,SOCK_STREAM, 0)),
    loopThreadPoolPtr_(std::make_shared<LoopThreadPool>(loopNumber))
    {
        accpetSocket_.bindAddress(ip, port);
        accpetSocket_.setReusePort(true);
        accpetSocket_.listen();
        loopThreadPoolPtr_->setMessageCallback(messageCallback_);   //设置消息回调
        loopThreadPoolPtr_->setCloseCallback(closeCallback_);
        loopThreadPoolPtr_->setWriteCompleteCallback(writeCompleteCallback_);
    }

    /*析构*/
    ~Acceptor()
    {
        accpetSocket_.close();
    }


/*loop池开启，接收新连接*/
    void start(void)
    {
        loopThreadPoolPtr_->start();
        struct sockaddr_in clientAddress;   //保存客户端地址
    
        while(1)
        {
        int connfd = accpetSocket_.accept(&clientAddress); //接收连接
        if(connfd > 0)
        {
            connectionhandle(connfd, clientAddress);
        }
        }
    }   




    /*设置新连接回调函数
    void setNewConnectionCallback(NewConnectionCallback cb)
    {
        newConnectionCallback_ = cb;
    }
*/

    Socket getSocket()
    {
        return accpetSocket_;
    }
private:
    std::shared_ptr<LoopThreadPool> loopThreadPoolPtr_;
    Socket    accpetSocket_;
    NewConnectionCallback newConnectionCallback_;
    MessageCallback messageCallback_;
    CloseCallback   closeCallback_;
    WriteCompleteCallback writeCompleteCallback_;
};

#endif
