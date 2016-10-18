/*************************************************************************
	> File Name: 7.1.1.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月08日 星期二 19时12分13秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Sales_data;
istream& read(istream &is,Sales_data &M);

class Sales_data
{
public:
    friend istream& read(istream &is,Sales_data &M);
        
    string isbn()
    {
        return bookNo;
    }
        
    int add (Sales_data trans)
    {
        return units_sold + trans.units_sold;
    }
        
    void print ()
    {
        cout << "bookNo " << bookNo << "  " 
             << "units_sold " << units_sold << " "
             << "price " << price << endl;
    }
private:
        string bookNo;
        double price;
        int units_sold;
};

istream& read(istream &is, Sales_data &M) 
{
    is >> M.bookNo >> M.price >> M.units_sold;
    return is;
}


int main()
{
    Sales_data total;
    if(read(cin,total)) {
        Sales_data trans;
        while (read(cin,trans)) {
            if (total.isbn() == trans.isbn()) {
                total.add(trans);
            } else {
                total.print();
                total = trans;
            }
        }
        total.print();
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}
