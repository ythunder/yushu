/*************************************************************************
	> File Name: 6.35.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年11月30日 星期一 21时14分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

int factorial (int val)
{
    if (val > 1) 
        return factorial (val - 1) * val;
    return 1;
}

int main()
{
    int val = 11;
    auto i = factorial (val);
    cout << i << endl;
    return 0;
}
