/*************************************************************************
	> File Name: EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 18时29分28秒
 ************************************************************************/


#include "EventLoop.h"
#include <sys/eventfd.h>
#include <sys/syscall.h>
#include <functional>
#include <unistd.h>
#include <memory>
#include <boost/scoped_ptr.hpp>



__thread EventLoop* t_loopInThisThread = 0;



/*初始化线程ID，线程间唤醒ID，设置唤醒事件的可读回调*/
EventLoop::EventLoop(int eventfd)
    :looping_(false),
    eventfd_(eventfd),
    quit_(false),
    threadId_(::syscall(SYS_gettid)),
    currentActiveChannel_(NULL),
    poller_(new Epoller()),
    wakeupChannel_(new Channel(eventfd, eventfd))
{
}


EventLoop::~EventLoop()
{
}


void EventfdReadCallback()
{
    

}



void 
EventLoop::loop()
{
    assert(!looping_);
    assert(assertInLoopThread() == true);
    looping_ = true;
    quit_ = false;
    
    updateChannel(wakeupChannel_);   //将loop自己的eventfd加入epoll中
    

    while(!quit_)
    {
        activeChannels_.clear();   //清空活跃事件
        if( (poller_->poll(10000, &activeChannels_)) > 0) 
        {
            std::cout << "event happend!" << std::endl;
        for(ChannelList::iterator it=activeChannels_.begin(); 
            it != activeChannels_.end();
            ++it)
        {
            currentActiveChannel_ = *it;
            currentActiveChannel_->handleEvent();
        }
        currentActiveChannel_ = NULL;
        }
    }
}

void 
EventLoop::quit()
{
    quit_ = true;
}



/**/
void 
EventLoop::updateChannel(Channel* channel)
{
    assert(channel->ownerLoop() == eventfd_);
    assert(assertInLoopThread() == true);
    poller_->updateChannel(channel);
}

void 
EventLoop::removeChannel(Channel* channel)
{
    assert(channel->ownerLoop() == eventfd_);
    assert(assertInLoopThread() == true);
    poller_->removeChannel(channel);
}

bool 
EventLoop::assertInLoopThread()
{
    static_cast<pid_t>(::syscall(SYS_gettid)) == threadId_;
}


