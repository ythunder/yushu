/*************************************************************************
	> File Name: Epoller.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月12日 星期六 00时31分48秒
 ************************************************************************/

#ifndef _EPOLLER_H
#define _EPOLLER_H

#include "Epoller.h"
#include <vector>
#include <map>
#include <sys/poll.h>

Epoller::Epoller(EventLoop* loop)
    :ownerLoop_(loop)
    epollfd_(::epoll_create(5)),
    events_(kInitEventListSize)
{
}

Epoller::~Epoller()
{
    ::close(epollfd_);
}


Timestamp 
Epoller::poll(int timeoutMs, ChannelList* activeChannels)
{
    int numEvents = ::epoll_wait(epollfd_,
                               &*events_.begin(),
                               static_cast<int>(events_.size()),
                               timeoutMs);
    
    Timestamp now(Timestamp::now());

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
        int saveError = errno;
        /**
         *标准错误判断
       */
    }
    return now;
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



/*未完成*/
void 
Epoller::updateChannnel(Channel* channel)
{
    fd = channel->fd();
    if(channels_.find(fd) == channels_.end())   //没发现fd
        channels_.push_back(channel);
    else
        cha

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
#endif
