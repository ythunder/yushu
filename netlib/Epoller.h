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

class EventLoop;
class Channel;

class Epoller
{

private:

    int kInitEventListSize = 16;

    int epollfd_;

    typedef std::map<int, Channel*> ChannelMap;
    ChannelMap channels_;

    int events_;  

    EventLoop* ownerLoop_;
public:
    typedef std::vector<Channel *> ChannelList;
    Epoller();
    ~Epoller();

    int poll(int timeoutMs, struct epoll_event* events);
    void updateChannel(int new_fd);
    void removeChannel(Channel* channel);
    void fillActiveChannels(int numEvents, ChannelList* activeChannels);

};

#endif
