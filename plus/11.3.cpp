/*************************************************************************
	> File Name: 11.3.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月16日 星期二 21时13分07秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: map;

int main()
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word) 
    {
        ++word_count[word];
    }
    for (auto &i : word_count)
    {
        cout << i.first << " occurs " << i.second << ((i.second > 1)? " times " : " time ") << endl;
    }
    }
