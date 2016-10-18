/*************************************************************************
	> File Name: 7.11.h
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月10日 星期四 21时45分58秒
 ************************************************************************/


#ifndef CP5_7.11_h
#define CP5_7.11_h

#include <iostream>
using namespace std;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : 
                bookNo(s), units_sold(n), revenue(p*n) {}

    Sales_data isbn(istream& is);
    Sales_data& combine(const Sales_data&);

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


istream& read(istream &is, Sales_data& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return *is;
}

istream& print(itream &os, Sales_data& item)
{
    os << "bookNo: " <<item.bookNo << "\n"
       << "units_sold: " << item.units_sold << "\n"
       << "revenue: " << item.revenue;
    return *os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    lhs.combine(rhs);
    return sum;
}

Sales_data :: Sales_data(itream &is)
{
    read(is, *this);
}

Sales_data& Sales_data :: combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
