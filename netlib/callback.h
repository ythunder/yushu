/*************************************************************************
	> File Name: callback.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月08日 星期二 22时55分56秒
 ************************************************************************/

#ifndef _CALLBACK_H
#define _CALLBACK_H

#include <functional>
#include "connection.h"
#include <memory>

namespace net
{
    typedef std::function<void(void)> ConnectionCallback;
    typedef std::function<void(std::shared_ptr<Connection>)> MessageCallback;
    typedef std::function<void(std::shared_ptr<connection>)> CloseCallback;
    typedef std::function<void(std::shared_ptr<Connection>)> WriteCompleteCallback;
}

#endif
