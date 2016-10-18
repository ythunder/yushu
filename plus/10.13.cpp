/*************************************************************************
	> File Name: 10.13.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 16时21分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std :: vector;
using std :: string;
using std :: sort;
using std :: partition;
using std :: cout;
using std :: endl;

bool predicate(const string& s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> v = {"a", "axsvsdvsvsv", "sdss", "sfscsc", "saca"};
    auto part = partition(v.begin(), v.end(), predicate);
    for (auto it = v.cbegin(); it != part; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
