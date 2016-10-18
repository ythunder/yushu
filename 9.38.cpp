/*************************************************************************
	> File Name: 9.38.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 03时31分00秒
    > Write a program to explore how vectors grow in the library you use.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using std :: vector;
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;

int main()
{
    vector<string> v;
    string s;

    while (cin >> s)
    {
        v.push_back(s);
        cout << v.size() << " ";
        cout << v.capacity() << endl;
    }
    return 0;
}

