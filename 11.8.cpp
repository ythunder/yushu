/*************************************************************************
	> File Name: 11.8.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月16日 星期二 22时47分25秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>

using std :: iterator;
using std :: cout;
using std :: cin;
using std :: vector;
using std :: string;
using std :: set;
using std :: endl;

int main()
{
    vector<string> vec;
    string word;

    while (cin >> word) {
        vec.push_back(word);   
    }
    set<string> s(vec.cbegin(), vec.cend());

    for (auto &i : s) 
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

