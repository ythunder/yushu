/*************************************************************************
	> File Name: 7.11.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月12日 星期六 20时29分55秒
 ************************************************************************/

#include <iostream>
#include "7.11.h"
using namespace std;

int main()
{
    Sales_data item1;
    print(cout, item1);

    Sales_data item2("yunting-13-4");
    print(cout, item2);;

    Sales_data item3("yunting-13-4", 3, 20.00);
    print(cout, item3);;

    Sales_data item4(cin);
    print(cout, item4) << endl;

    return 0;
}


