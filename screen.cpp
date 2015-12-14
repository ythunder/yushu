/*************************************************************************
	> File Name: screen.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月14日 星期一 13时32分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Screen {
public:
    typedef string :: size_type pos;
private:
    pos cursor = 0;
    pos height = 0,width = 0;
    string contents;
};


