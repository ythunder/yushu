/*************************************************************************
	> File Name: sock_client.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月10日 星期四 14时28分04秒
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
#include <iostream>

int main()
{

    char* ip = "127.0.0.1";
    int port = 8888;

    char* buf = "hello\n";
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    int client_sock = socket(PF_INET, SOCK_STREAM, 0);
    
    Socket clientsock(client_sock);

    clientsock.connect((sockaddr*)&server_addr);

    clientsock.write((void*)buf, sizeof buf);

    sleep(10);

    clientsock.close();

    return 0;
}
