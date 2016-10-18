/*************************************************************************
	> File Name: 9.14.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月30日 星期六 22时21分56秒
    > Write a program to assign the elements from a list of char* pointers to C-style character strings.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std :: vector;
using std :: list;
using std :: string;
using std :: endl;
using std :: cout;

int main()
{
    list<const char*> lis{"Milton", "Shake", "Austen"};
    vector<string> vec;
    vec.assign(lis.cbegin(), lis.cend());
    for (const auto& ch : vec) 
    {
        cout << ch << endl;
    }
    return 0;
}

