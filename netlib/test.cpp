/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年12月14日 星期三 19时28分45秒
 ************************************************************************/

#include "MemcacheServer.h"
#include "Message.cpp"
#include<iostream>
#include "Acceptor.h"
#include <string>
#include <string.h>
#include "callback.h"
#include <functional>
#include "Connection.h"
#include <memory>

class Message;
class Connection;

/*
int main()
{
    
    Message mess;

    std::string ip ="127.0.0.1";
    int port = 8888;

    Acceptor acceptor(ip, port, 3);

//    acceptor.setMessageCallback(std::bind(&Message::test, std::placeholders::_1, std::placeholders::_2));
    
    //MessageCallback cb = std::bind(&Message::test, &mess, std::placeholders::_1, std::placeholders::_2);

   // std::shared_ptr<Connection> a ;
 //   cb(a,&a->get_inputbuffer());


    //acceptor.setMessageCallback(cb);
    acceptor.setMessageCallback(std::bind(&Message::test, mess, std::placeholders::_1, std::placeholders::_2));

    acceptor.start();

}*/


int main()
{
    std::string ip = "127.0.0.1";
    int port = 8888;
    MemcacheServer server(ip, port, 3);
    server.memcacheServerStart();
}
