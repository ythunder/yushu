/*************************************************************************
	> File Name: EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 18时29分28秒
 ************************************************************************/

#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H

#include "EventLoop.h"


__thread EventLoop* t_loopInThisThread = 0;

int createEventfd()
{
    int evtfd = :;eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd < 0)
    {

    }
    return evtfd;
}

EventLoop::EventLoop()
    :looping_(false),
    quit_(false),

{
    
}
    ~EventLoop();

void 
EventLoop::loop()
{
    assert(!looping_);
    assert(assertInLoopThread());

}

    void quit();

    void runInLoop(const Funtor& cb);

    void queueInLoop(const Functor& cb);

    void wakeup();

    void updateChannel(Channel* channel);

    void removeChannel(Channel* channel);

    bool assertInLoopThread()
    {
        static_cast<pid_t>(::syscall(SYS_gettid)) == threadId_;
    }

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
