/*************************************************************************
	> File Name: 11.12.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月17日 星期三 00时15分50秒
 ************************************************************************/

#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<pair<string, int>>  vec;
    string str;
    int i;
    while(cin >> str >> i) 
    {
        vec.push_back(pair<string, int>(str, i));
    }

    for (const auto &p : vec)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
