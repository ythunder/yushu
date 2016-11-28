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

int createEventfd()
{
    int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd < 0)
    {

    }
    return evtfd;
}


/*初始化线程ID，线程间唤醒ID，设置唤醒事件的可读回调*/
EventLoop::EventLoop()
    :looping_(false),
    quit_(false),
    threadId_(::syscall(SYS_gettid)),
    wakeupFd_(createEventfd()),
    wakeupChannel_(new Channel(this, wakeupFd_)),
    currentActiveChannel_(NULL)
{
    if(!t_loopInThisThread)
        t_loopInThisThread = this;
    wakeupChannel_->setReadCallback(
        boost::bind(&EventLoop::handleRead, this)
        );
    wakeupChannel_->enableReading();
}


EventLoop::~EventLoop()
{
    ::close(wakeupFd_);
}

void 
EventLoop::loop()
{
    assert(!looping_);
    assert(assertInLoopThread() == true);
    looping_ = true;
    quit_ = false;
    while(!quit_)
    {
        activeChannels_.clear();   //清空活跃事件
        poller_->poll(10000, &activeChannels_);
    }
    for(ChannelList::iterator it=activeChannels_.begin(); 
       it != activeChannels_.end();
       ++it)
    {
        currentActiveChannel_ = *it;
        currentActiveChannel_->handleEvent();
    }
    currentActiveChannel_ = NULL;
    doPendingFunctors();
}

void 
EventLoop::quit()
{
    quit_ = true;
    if(threadId_ != syscall(SYS_gettid))
    {
        wakeup();
    }

}



void 
EventLoop::handleRead()
{
    uint64_t one = 1;
    ssize_t n = read(wakeupFd_, &one, sizeof one);
}


void 
EventLoop::runInLoop(const Functor& cb)
{
    if(assertInLoopThread() == true)
    {
        cb();
    }
    else
    {
        queueInLoop(cb);
    }
}



/*等会加个锁吧
* 加入pendingFunctors,如果不在当前线程，唤醒*/
void
EventLoop::queueInLoop(const Functor& cb)
{
    pendingFunctors_.push_back(cb);
    if(assertInLoopThread() == false)
    {
        wakeup();
    }
}


/*唤醒时，在eventfd中写入一个字节数据*/
void 
EventLoop::wakeup()
{
    uint64_t one = 1;
    ssize_t n = write(wakeupFd_, &one, sizeof one);
}


/**/
void 
EventLoop::updateChannel(Channel* channel)
{
    assert(channel->ownerLoop() == this);
    assert(assertInLoopThread() == true);
    poller_->updateChannel(channel);
}

void 
EventLoop::removeChannel(Channel* channel)
{
    assert(channel->ownerLoop() == this);
    assert(assertInLoopThread() == true);
    poller_->removeChannel(channel);
}

bool 
EventLoop::assertInLoopThread()
{
    static_cast<pid_t>(::syscall(SYS_gettid)) == threadId_;
}


