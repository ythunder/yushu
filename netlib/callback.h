/*************************************************************************
	> File Name: callback.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月08日 星期二 22时55分56秒
 ************************************************************************/

#ifndef _CALLBACK_H
#define _CALLBACK_H

#include <functional>
#include "TcpConnection.h"
#include <memory>

    typedef std::function<void(void)> ConnectionCallback;
    typedef std::function<void(std::shared_ptr<TcpConnection>)> MessageCallback;
    typedef std::function<void(std::shared_ptr<TcpConnection>)> CloseCallback;
    typedef std::function<void(std::shared_ptr<TcpConnection>)> WriteCompleteCallback;
    typedef std::function<void(int, struct sockaddr_in)> NewConnectionCallback;
#endif
