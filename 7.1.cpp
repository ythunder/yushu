/*************************************************************************
	> File Name: 7.1.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月05日 星期六 16时35分36秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
    string  bookNo;
    unsigned  unit_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;

    if (cin >> total.bookNo >> total.unit_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.unit_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.unit_sold += trans.unit_sold;
                total.revenue += total.revenue;
            } else {
                cout << total.bookNo << " " << total.unit_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.unit_sold << " " << total.revenue << endl;
    }
    else {
        cerr << "no data!" << endl;
    }
}
