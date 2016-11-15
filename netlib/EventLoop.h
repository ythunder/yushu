/*************************************************************************
	> File Name: EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 18时29分28秒
 ************************************************************************/

#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H

#include <vector>
#include "Channel.h"
#include "Poller.h"
#include <functional>

class EventLoop
{
public:
    typedef std::function<void()> Funtor;

    EventLoop();
    ~EventLoop();

    void loop();

    void quit();

    void runInLoop(const Funtor& cb);

    void queueInLoop(const Functor& cb);

    void wakeup();

    void updateChannel(Channel* channel);

    void removeChannel(Channel* channel);

    bool assertInLoopThread();

private:
    bool looping_;
    bool quit_;
    const pid_t threadId_;
    Timestamp pollReturnTime_;
    boost::scoped_ptr<Epoller> poller_;
    boost::scoped_ptr<TimeQueue> timerQueue_;
    int wakeupFd_;
    boost::scoped_ptr<Channel> wakeupChannel_;
};

#endif
