/*************************************************************************
	> File Name: Message.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月22日 星期三 02时19分21秒
 ************************************************************************/

#include<iostream>
#include "Connection.h"
#include <memory>
#include <stdio.h>

class Message
{
public:
    void test(std::shared_ptr<Connection> c , Buffer* b)
    {
        printf("测试\n");
    }

};
