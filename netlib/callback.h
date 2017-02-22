/*************************************************************************
	> File Name: callback.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月08日 星期二 22时55分56秒
 ************************************************************************/


#include <functional>
#include "Connection.h"
#include <memory>

class Connection;

    typedef std::function<void(void)> ConnectionCallback;
    typedef std::function<void(std::shared_ptr<Connection>, Buffer*)> MessageCallback;
    typedef std::function<void(std::shared_ptr<Connection>)> CloseCallback;
    typedef std::function<void(std::shared_ptr<Connection>)> WriteCompleteCallback;
    typedef std::function<void(int, struct sockaddr_in)> NewConnectionCallback;
