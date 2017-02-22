/*************************************************************************
	> File Name: EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 18时29分28秒
 ************************************************************************/

#include "objectPool.h"
#include "Connection.h"
#include "event_loop.h"
#include <sys/eventfd.h>
#include <sys/syscall.h>
#include <functional>
#include <unistd.h>
#include <memory>
#include <sys/poll.h>
#include <sys/epoll.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>

__thread EventLoop* t_loopInThisThread = 0;



/*初始化线程ID，线程间唤醒ID，设置唤醒事件的可读回调*/
EventLoop::EventLoop(int eventfd)
    :looping_(false),
    eventfd_(eventfd),
    quit_(false),
    threadId_(::syscall(SYS_gettid)),
    poller_(new Epoller()),
    objectPool_(1024, 0, poller_)
{
}


EventLoop::~EventLoop()
{
}



void
EventLoop::handleEventFdRead()
{
    int loop_eventfd = getloop_eventfd();
    ssize_t conn_buff;
    ssize_t ret = read(loop_eventfd, &conn_buff, sizeof(conn_buff));

    std::stringstream stream_loop, stream_conn;
    std::string loop_string, conn_string;
    stream_loop << loop_eventfd;
    stream_loop >> loop_string;
    stream_conn << conn_buff;
    stream_conn >> conn_string; 
        
    std::string last_cout = "loop" + loop_string  + "收到一个客户端连接socket为" + conn_string;

    int client_fd = static_cast<int>(conn_buff);
    std::cout << last_cout << std::endl;
    poller_->updateChannel(client_fd);     //将新来的客户socket加入事件表

    //从连接池中取出连接,给智能指针自定义删除器,将连接放回连接池
    std::shared_ptr<Connection> connectionPtr(objectPool_.getObject(),[&](Connection *p){objectPool_.giveBackObject(p);});

    connectionPtr-> set_fd(client_fd);
    connectionPtr->set_epoll(poller_);

    //将客户端及对应的连接加入到map中
    connectionMap_.insert(std::pair<int,std::shared_ptr<Connection>>(client_fd, connectionPtr));

}



void 
EventLoop::handleRead(int fd)
{
    char buff[30];
    ssize_t bb = read(fd, &buff, sizeof(buff));

    if(bb > 0) 
    {
        std::stringstream stream_bit;
        std::string bit_string;
        stream_bit << bb;
        stream_bit >> bit_string;

        std::string last_cout = "触发读事件，读得" + static_cast<std::string>(buff) + "共" + bit_string + "字节";
        std::cout <<  last_cout << std::endl;   

        /*
        std::cout << "Connection:" << fd  << std::endl;
        Buffer buffer = connectionMap_[fd]->get_inputbuffer();

        std::cout << "buffer 中可读字节数" << buffer.readableSize() << std::endl;
*/
        messageCallback_(connectionMap_[fd], &connectionMap_[fd]->get_inputbuffer());
    }

    else if(bb == 0) {
        handleClose(fd);
    }
}


void 
EventLoop::handleClose(int fd)
{
    std::cout << "客户端关闭"<<std::endl;
    close(fd);  
}


void 
EventLoop::loop()
{
    assert(!looping_);
    looping_ = true;
    quit_ = false;
    
    int loop_eventfd = getloop_eventfd();
    poller_->updateChannel(loop_eventfd);   //将loop自己的eventfd加入epolal中

    int i=0;

    struct epoll_event events[16];

    while(quit_ == false)
    {
        memset(&events, 0, sizeof(events));
        int re =  poller_->poll(0, events);

        if(re > 0)
        { 
            for(int j=0; j<re; ++j)
            {
                std::cout << "\n\n";
                if(events[j].data.fd == loop_eventfd)   //客户端请求连接
                {
                    handleEventFdRead();
                }
                else if(events[j].data.fd > 0) {
                    handleRead(events[j].data.fd);
                }
            }
        }   
    }
}


void 
EventLoop::quit()
{
    quit_ = true;
}





void 
EventLoop::removeChannel(Channel* channel)
{
    assert(channel->ownerLoop() == eventfd_);
    poller_->removeChannel(channel);
}



