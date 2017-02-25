/*************************************************************************
	> File Name: Connection.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月21日 星期二 16时04分22秒
 ************************************************************************/

#ifndef CONN_H
#define CONN_H

#include "Buffer.h"
#include "Epoller.h"
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <memory>
#include <string>
#include <sys/epoll.h>
#include <sys/poll.h>


class Epoller;

class Connection
{
public:
    
    Connection(int fd, std::shared_ptr<Epoller> epoll) 
        :fd_(fd),
        epoll_(epoll) 
    {

    }

    ~Connection()
    {
        
    }

    int send(void)
    {
        int ableWrites = outputBuffer_.readableSize();
        assert(ableWrites >= 0);
        int writeBytes = outputBuffer_.writeToFd(fd_);

        if(writeBytes < 0) {
            printf("发送数据出错\n");
        }
        else if(writeBytes < ableWrites) {
            registerWriteEvent();
        }
        else if(writeBytes == ableWrites) {
            deleteWriteEvent();
        }
        return writeBytes;
    }

    void set_fd(int fd)
    {
        fd_ = fd;
    }

    void set_epoll(std::shared_ptr<Epoller> &epoll)
    {
        epoll_=epoll;
    }

    //注册写事件
    void registerWriteEvent(void)
    {
        int events = EPOLLIN | EPOLLOUT;
       // epoll_->modFd(fd, events);
    }

    void deleteWriteEvent(void)
    {
        int events = EPOLLIN;
    //    epoll_->modFd(fd_, events);
    }


    Buffer& get_inputBuffer() 
    {
        return inputBuffer_;
    }

    Buffer& get_outputBuffer()
    {
        return outputBuffer_;
    }
    

    int get_fd()
    {
        return fd_;
    }

private:
    int fd_;   //标示此连接的描述符
    std::string ConnectionName_;  //连接名字
    Buffer inputBuffer_;    //输入buffer
    Buffer outputBuffer_;   //输出buffer
    std::shared_ptr<Epoller> epoll_;  //该连接所运行的epoll
};


#endif
