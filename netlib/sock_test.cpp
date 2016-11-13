/*************************************************************************
	> File Name: sock_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 22时35分59秒
 ************************************************************************/

#include "Socket.h"
#include "Socket.cpp"
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

int main()
{
    char *ip = "127.0.0.1";
    int port = 8888;
    char buf[1024];

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);

    Socket sock(listenfd);

    sock.bindAddress(ip, port);

    sock.listen();

    while(1)
    {
        struct sockaddr_in* peeraddr;

        int connfd = sock.accept(peeraddr);

        sleep(15);

       sock.read(connfd, (void*)&buf, sizeof(buf));

    }

    return 0;
}
