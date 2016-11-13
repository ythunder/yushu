/*************************************************************************
	> File Name: Epoller.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月12日 星期六 00时31分48秒
 ************************************************************************/

#ifndef _EPOLLER_H
#define _EPOLLER_H

#include <vector>

struct epoll_event;

class Epoller
{
public:
    Epoller(EventLoop* loop);
    ~Epoller();

    Timestamp poll(int timeoutMs, ChannelList* activeChannels);
    void updateChannnel(Channel* channel);
    void removeChannel(Channel* channel);

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
