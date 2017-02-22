/*************************************************************************
	> File Name: Eventloop_Threadpool.h
	> Author: 
	> Mail: 
	> Created Time: 2016年12月14日 星期三 16时38分35秒
 ************************************************************************/

#include "Eventloop_Threadpool.h"
#include <map>
#include <vector>
#include <sys/eventfd.h>
#include <thread>
#include <memory>
#include <functional>
#include <iostream>
#include "event_loop.h"
#include <utility>
#include <unistd.h>
#include <sstream>

void threadFunc(int eventfd, LoopThreadPool *loopThreadPool);

LoopThreadPool::LoopThreadPool(int number)
    :loopNumber_(number)
{
    next_ = 1;
}

LoopThreadPool::~LoopThreadPool()
{
    for(auto &t : threadVector_)
    {
        t->join();
    }
}


/*得到要分配的loop的fd*/
int 
LoopThreadPool::getNextLoop()
{
    std::map<int,int> map;
    int fd = fdMap_[next_];
    if(next_ == loopNumber_)
    {
        next_ = 1;
    }
    else
    {
        next_++;
    }
    return fd;
}



/*创建evenfd, 创建线程处理*/
void 
LoopThreadPool::start()
{
    int fd;
    for(int i=0; i<loopNumber_; ++i)
    {
        sleep(1);
        fd = createEventFd();
        fdMap_.insert(std::pair<int,int>(i+1, fd));   //用数字对应fd存入fd_Map
        
        threadVector_.push_back(std::make_shared<std::thread>(threadFunc, fd, this));  //将新创建对象加入容器
    }
}


/*创建一个eventfd*/
int 
LoopThreadPool::createEventFd()
{
    int fd;
    if((fd = ::eventfd(0,EFD_NONBLOCK))  == -1) 
    {
        std::cout << "create eventfd failed!" << std::endl;
    }
    return fd;
}


void threadFunc(int eventfd, LoopThreadPool *loopThreadPool)
{
    std::stringstream stream_eventfd;
    std::string evenfd_string;
    stream_eventfd << eventfd;
    stream_eventfd >> evenfd_string;

    std::string last_string = "创建一个线程，evenfd为" + evenfd_string ;
    std::cout << last_string << std::endl;
    EventLoop loop(eventfd);
    loop.loop();                //启动循环
}

