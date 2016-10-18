/*************************************************************************
	> File Name: 6.25.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年11月28日 星期六 11时09分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
    char *p = argv[1];

    while (*argv[1] != '\0') {
        *argv[1]++;
    }
    while (*argv[2] != '\0') {
    *argv[1]++ = *argv[2]++;
    }
    cout << p << endl;
    return 0;
}
