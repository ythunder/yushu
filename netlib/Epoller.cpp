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


Epoller::Epoller()
    :epollfd_(::epoll_create(5)),
    events_(kInitEventListSize)
{
}

Epoller::~Epoller()
{
    ::close(epollfd_);
}


/*将epoll_wait得到的活跃事件表逐个包装成channel加入activeChannels*/
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


int 
Epoller::poll(int timeoutMs, ChannelList* activeChannels)
{

    int numEvents = ::epoll_wait(epollfd_,
                               &*events_.begin(),
                               static_cast<int>(events_.size()),
                               timeoutMs);

    if(numEvents > 0)
    {
        fillActiveChannels(numEvents, activeChannels);
    }
    else if(numEvents == 0)
    {
        std::cout << "没有活跃事件\n";
    }
    else
    {
        
         //标准错误判断
    }

    return numEvents;
}




void 
Epoller::updateChannel(Channel* channel)
{
    struct epoll_event event;
    bzero(&event, sizeof(event));
    event.events = channel->events();
    event.data.ptr = channel;
    int fd = channel->fd();
    if( ::epoll_ctl(epollfd_,EPOLL_CTL_ADD, fd, &event) < 0)
    {
        int saveError = errno;
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

/*
private:
    int kInitEventListSize = 16;

    int epollfd_;

    typedef std::map<int, Channel*> ChannelMap;
    ChannelMap channels_;

    typedef std::vector<struct epoll_event> EventList;
    EventList events_;  

    EventLoop* ownerLoop_;
};
*/
