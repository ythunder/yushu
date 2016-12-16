/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年12月14日 星期三 19时28分45秒
 ************************************************************************/

#include<iostream>
#include "Acceptor.h"


int main()
{
    char* ip ="127.0.0.1";
    int port = 9999;

    Acceptor acceptor(ip, port, 3);

    acceptor.start();

}
