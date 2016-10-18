/*************************************************************************
	> File Name: 10.27.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 17时43分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std :: vector;
using std :: list;
using std :: cout;
using std :: endl;
using std :: unique_copy;

int main()
{
    vector<int> vec = {1,1,2,3,3,3,6,9};
    list<int> lis;

    unique_copy(vec.begin(), vec.end(), back_inserter(lis));
    for (auto &i : lis)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
