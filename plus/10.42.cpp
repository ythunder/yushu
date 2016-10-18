/*************************************************************************
	> File Name: 10.42.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月16日 星期二 03时16分55秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <list>

using std :: string;
using std :: list;
using std :: cout;
using std :: endl;

void elimDups(list<string>& words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> lis = {"ax", "dx", "ax", "faaaaa", "ax"};
    elimDups(lis);
    for (auto &i : lis) 
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
