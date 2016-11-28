/**********************************************************************
    > File Name: Epoller.h
    > Author: 
    > Mail: 
    >  Created Time: 2016年11月12日 星期六 00时31分48秒
 ************************************************************************/

#ifndef _EPOLLER_H
#define _EPOLLER_H

#include "Timestamp.h"
#include <map>
#include <vector>
#include "Channel.h"
#include "EventLoop.h"

//struct epoll_event;

class Epoller
{

public:
    typedef std::vector<Channel*> ChannelList;
    Epoller(EventLoop* loop);
    ~Epoller();

    Timestamp poll(int timeoutMs, ChannelList* activeChannels);
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    void fillActiveChannels(int numEvents, ChannelList* activeChannels);

private:
    int kInitEventListSize = 16;

    int epollfd_;

    typedef std::map<int, Channel*> ChannelMap;
    ChannelMap channels_;

    typedef std::vector<struct epoll_event> EventList;
    EventList events_;  

    EventLoop* ownerLoop_;
};

#endif
