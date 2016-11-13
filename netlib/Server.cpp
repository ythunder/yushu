/*************************************************************************
	> File Name: Server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月08日 星期二 22时49分49秒
 ************************************************************************/
#include"Server.h"
#include <memory>
#include <string>

using namespace net;

Server::Server(std::string ip, int port, int loopNumber)
    :baseLoopPtr_(std::make_shared<BaseLoop>(ip,port,loopNumber))
{

}

Server::~Server()
{
    
}

void Server::start()
{
    baseLoopPtr_->setConnectionCallback(connectioncallback_);
    baseLoopPtr_->setMessageCallback(messagecallback_);
    baseLoopPtr_->setCloseCallback(closecallback_);
    baseLoopPtr_->setWriteCompletecallback(writecompletecallback_);
    baseLoopPtr_->start();
}


