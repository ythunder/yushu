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
#include <sys/poll.h>
#include <sys/epoll.h>
#include <string.h>


__thread EventLoop* t_loopInThisThread = 0;



/*初始化线程ID，线程间唤醒ID，设置唤醒事件的可读回调*/
EventLoop::EventLoop(int eventfd)
    :looping_(false),
    eventfd_(eventfd),
    quit_(false),
    threadId_(::syscall(SYS_gettid)),
    poller_(new Epoller()),
    wakeupChannel_(new Channel(eventfd, eventfd))
{
}


EventLoop::~EventLoop()
{
}



void 
EventLoop::loop()
{
    assert(!looping_);
    assert(assertInLoopThread() == true);
    looping_ = true;
    quit_ = false;
    
    int loop_eventfd = getloop_eventfd();
    poller_->updateChannel(loop_eventfd);   //将loop自己的eventfd加入epolal中

    int i=0;

    struct epoll_event events[16];
    while(quit_ == false)
    {
        sleep(3);
        ++i;
        memset(&events, 0, sizeof(events));
        int re =  poller_->poll(0, events);

        std::cout << "ret = " << re << std::endl;

        if(re > 0)
        {
            std::cout << "EventLoop.cpp文件：发现活跃事件" << std::endl;
            for(int j=0; j<16;++j)
            {
                std::cout << "activefd = " << events[j].data.fd << std::endl;
                if(events[j].data.fd == loop_eventfd)
                {
                    std::cout << "eventfd accept new connfd"<< std::endl;
                    ssize_t conn_buff;
                    ssize_t ret = read(loop_eventfd, &conn_buff, sizeof(conn_buff));
                    poller_->updateChannel(static_cast<int>(conn_buff));
                }

                if(events[j].events & EPOLLIN)
                {
                    std::cout << "触发读事件\n";
                }
                else if(events[j].events & EPOLLOUT)
                {
                    std::cout << "触发写事件\n";
                }
            }
        }       
    }
}   

void 
EventLoop::quit()
{
    quit_ = true;
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


