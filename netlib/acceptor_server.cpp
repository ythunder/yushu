/*************************************************************************
	> File Name: acceptor_sock.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月13日 星期日 21时11分47秒
 ************************************************************************/

#include "Acceptor.h"

int main()
{
    EventLoop loop;
    Acceptor acceptor(&loop, "127.0.0.1", 8888);

    acceptor.listen();

    return 0;
}
