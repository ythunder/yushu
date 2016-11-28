/*************************************************************************
	> File Name: sock_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 22时35分59秒
 ************************************************************************/
#include "Acceptor.h"
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/types.h>
#include <netinet/tcp.h>

void 
conn_back(int connfd, struct sockaddr_in peer)
{
    std::cout << "connfd: " << connfd << std::endl;
}


int main()
{
    char *ip = "127.0.0.1";
    int port = 8888;
    char buf[1024];

    EventLoop *eventloop;

    Acceptor acceptor(eventloop,ip,port);

    acceptor.setNewConnectionCallback(conn_back);

    acceptor.listen();

    return 0;
}
