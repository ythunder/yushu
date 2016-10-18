/*************************************************************************
	> File Name: 10.1.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月14日 星期日 12时04分22秒
    >The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Write a program, read a sequence of ints into a vector and print the count of how many elements have a given value.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std :: vector;
using std :: cout;
using std :: count;
using std :: endl;

int main()
{
    vector<int> v = {1,2,3,4,5,6,6,3,6,3};
    cout << count(v.cbegin(), v.cend(), 6) << endl;
}

