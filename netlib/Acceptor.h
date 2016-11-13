/*************************************************************************
	> File Name: Acceptor.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月11日 星期五 14时25分50秒
 ************************************************************************/

#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H

#include "Socket.h"
#include "Channel.h"

class Acceptor
{
public:
    Acceptor(EventLoop *loop, const );

private:
    EventLoop *loop_;
    Socket    accpetSocket_;
    Channel   acceptChannel_;
    NewConnectionCallback newConnectionCallback_;
};

#endif
