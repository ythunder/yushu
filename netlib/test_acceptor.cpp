/*************************************************************************
	> File Name: test_acceptor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月14日 星期一 22时51分00秒
 ************************************************************************/

#include <iostream>
#include "Acceptor.h"

void newConnection(int fd, struct sockaddr_in* peeraddr)
{
    printf("new connection from \n");
}

int main()
{
    printf("main pid =  %d\n", getpid());

    return 0;
}

