/*************************************************************************
	> File Name: 9.41.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 03时47分54秒
    > Write a program that initializes a string from a vector<char>.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using std :: vector;
using std :: string;
using std :: cout;
using std :: endl;

int main()
{
    vector<char> vec{'y', 'u', 'n'};
    string str(vec.begin(), vec.end());
    cout << str << endl;
    return 0;
}

