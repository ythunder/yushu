/*************************************************************************
	> File Name: 9.15.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月30日 星期六 23时51分59秒
    > Write a program to determine whether two vector<int>s are equal.
 ************************************************************************/

#include <iostream>
#include <vector>

using std :: vector;
using std :: cout;
using std :: endl;

int main()
{
    vector<int> vec1{1,2,3,4,5};
    vector<int> vec2{1,2,3,4,5};
    vector<int> vec3{1,2,3,4};

    cout << (vec1 == vec2) << endl;
    cout << (vec1 == vec3) << endl;

    return 0;
}

