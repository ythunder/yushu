/*************************************************************************
	> File Name: 6.22.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年11月26日 星期四 13时16分35秒
 ************************************************************************/

#include <iostream>
using namespace std;

void exchange(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a=3, b=4;
    cout << "a = " << a << "\tb = " << b << endl;
    exchange(&a, &b);
    cout << "exchange... a = " << a << "\tb = " << b << endl;
    return 0;   
}
