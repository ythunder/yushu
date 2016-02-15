/*************************************************************************
	> File Name: 10.30.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月16日 星期二 02时10分10秒
    > Use stream iterators, sort, and copy to read a sequence of intergers from the standard input, sort them, and then write them back to the standard output.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std :: istream_iterator;
using std :: vector;
using std :: sort;
using std :: copy;
using std :: ostream_iterator;
using std :: cin;
using std :: cout;
using std :: endl;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec;
    ostream_iterator<int> out_iter(cout, " ");
    while (in_iter != eof) 
    {
        vec.push_back(*in_iter++);
    }
    sort(vec.begin(), vec.end());
    copy (vec.begin(), vec.end(), out_iter);

    return 0;
}


