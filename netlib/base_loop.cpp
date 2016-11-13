/*************************************************************************
	> File Name: base_loop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 00时47分20秒
 ************************************************************************/


#include "base_loop.h"

using namespace net;


BaseLoop::BaseLoop(int loopNumber)
{
    LoopThreadPoolPtr_(std::make_shared<LoopThreadPool>(loopNumber));
}

BaseLoop::~BaseLoop()
{
    close(listenfd_);
}

int 
BaseLoop::CreatedListenFd(void)
{
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);

    Socket listenfd(sock);

    listenfd.bindAddress("127.0.0.1", 8888);

    listenfd.listen();

    return listenfd;
}


void 
BaseLoop::start(void)
{
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int connfd;
    listenfd_ = CreatedListenFd();
    loopThreadPoolPtr_->setMessageCallback(messageCallback_);   //设置读回调函数
        loopThreadPoolPtr_->setCloseCallback(closeCallback_);  //设置关闭回调函数
        loopThreadPoolPtr_->setWriteCompleteCallback(writeCompleteCallback_);
        loopThreadPoolPtr_->start();        //开启loop线程池

    while(1)
    {
        connfd = accpt(listenfd_, (struct sockaddr *)&client_addr, &len);
        connectionHandle(connfd);
    }
}


void 
BaseLoop::connectionHandle(int connfd)  //连接回调
{
    int fd = LoopThreadPoolPtr_->getNextLoop();
    uint64_t buff = connfd;
    int ret = write(fd, &buffer, sizeof(buff));  //添加到指定的loop循环中
    assert(ret == sizeof(buff));
}


#endif
