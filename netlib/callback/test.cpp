/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月22日 星期三 14时43分25秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <functional>

typedef std::function<void(int,int)> MessageCallback;

class M
{
public:
    void max(int a, int b)
    {
        printf("测试\n");
    }
};


int main()
{
    M mm;
    MessageCallback cb(std::bind(&M::max, mm, std::placeholders::_1,std::placeholders::_2));
    cb(1,2);
    return 0;
}

