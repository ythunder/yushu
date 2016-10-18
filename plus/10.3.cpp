/*************************************************************************
	> File Name: 10.3.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月14日 星期日 21时56分00秒
    >　Use accumulate to sum the elements in a vector<int>.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using std :: vector;
using std :: cout;
using std :: endl;
using std :: accumulate;

int main()
{
    vector<int> vec = {1,2,4,2,5,2,4,7};
    
    auto sum = accumulate(vec.cbegin(), vec.cend(), 0);

    cout << "sum = " << sum << endl;
}
