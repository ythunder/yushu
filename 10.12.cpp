/*************************************************************************
	> File Name: 10.12.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 15时35分01秒
    > Write a function named compareIsbn that compares the isbn() members of two Sales_data objects. Use that funtion to sort a vector that holds Sales_data objects.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "Sale_data.h"

using std :: vector;
using std :: string;
using std :: sort;
using std :: cout;
using std :: endl;

inline bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2)
{
    return sd1.isbn().size() < sd2.isbn().size();
}
int main()
{
    Sales_data d1("aa"),d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> v{d1, d2, d3, d4, d5};
    sort(v.begin(), v.end(), compareIsbn);

    for (const auto &element : v)
    {
        cout << element.isbn() << " ";
    }
    cout << endl;

    return 0;
}


