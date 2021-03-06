/*************************************************************************
	> File Name: Epoller.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月12日 星期六 00时31分48秒
 ************************************************************************/

#include <iostream>
#include "Epoller.h"
#include <vector>
#include <map>
#include <sys/epoll.h>
#include <string.h>
#include <unistd.h>
#include <sstream>



Epoller::Epoller()
    :epollfd_(::epoll_create(5)),
    events_(kInitEventListSize)
{
}

Epoller::~Epoller()
{
    ::close(epollfd_);
}


/*//将epoll_wait得到的活跃事件表逐个包装成channel加入activeChannels
void 
Epoller::fillActiveChannels(int numEvents, ChannelList* activeChannels)
{
    for(int i=0; i<numEvents; ++i)
    {
        Channel* channel = static_cast<Channel*>(events_[i].data.ptr);
        channel->set_revents(events_[i].events);
        activeChannels->push_back(channel);
    }
}
*/

int 
Epoller::poll(int timeoutMs, struct epoll_event* events)
{
    int numEvents = ::epoll_wait(epollfd_,
                               events,
                               events_,
                               timeoutMs);
    if(numEvents < 0)
    {
        int saveError = errno;
        std::cout << "errno = " << saveError;
         //标准错误判断
    }

    return numEvents;
}



void 
Epoller::updateChannel(int new_fd)
{
    std::stringstream stream_newfd;
    std::string newfd_string;
    stream_newfd << new_fd;
    stream_newfd >> newfd_string;

    std::string last_string = "new_fd传入Poller监听队列，new_fd = " + newfd_string;
    std::cout << last_string << std::endl;

    struct epoll_event event;
    bzero(&event, sizeof(event));
    event.data.fd = new_fd;
    event.events = EPOLLIN;
    if( ::epoll_ctl(epollfd_,EPOLL_CTL_ADD, new_fd, &event) < 0)
    {
        std::cout << "Epoller.cpp 文件出错了"<< std::endl;
        int saveError = errno;
        std::cout << "epoll_ctl errno = " << saveError << std::endl;
        /*错误处理*/
    }
}

void 
Epoller::removeChannel(Channel* channel)
{
    int fd = channel->fd();
    if(channels_.find(fd) != channels_.end() && channels_[fd] == channel)   //找到
    {
        channels_.erase(fd);   //事件不用不用，删掉
    }
}

