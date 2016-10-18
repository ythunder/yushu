/*************************************************************************
	> File Name: 6.21.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年11月26日 星期四 13时03分47秒
 ************************************************************************/

#include <iostream>
using namespace std;

int compare (int a, int *p)
{
    if (a < *p) 
        return *p;
    else return a;
}

int main()
{
    int a = 10, p = 60;
    int max;
    max = compare (a, &p);
    cout << max << endl;
    return 0;
}
