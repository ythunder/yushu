/*************************************************************************
	> File Name: 9.26.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 02时27分54秒
    > using the following definition of ia, copy ia into a vector and into a list. Using the single-iterator form of erase to remove the elements with odd values from your list and the even values from your vector.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>

using std :: vector;
using std :: list;
using std :: cout;
using std :: endl;
using std :: end;

int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

    vector<int> vec(ia, end(ia));
    list<int> lis(vec.begin(), vec.end());

    auto v = vec.begin();
    while(v != vec.end()) 
    {
        if ( !(*v % 2) )
        {
            v = vec.erase(v);   
        }
        else 
        {
            ++v;
        }
    }
    for (auto &v : vec) 
    {
        cout << v << " ";
    }
    cout << endl;
    auto l = lis.begin();
    while (l != lis.end())
    {
        if (*l % 2) {
            l = lis.erase(l);
        }
        else
        {
            ++l;    
        }
    }
    for (auto &l : lis) 
    {
        cout << l << " ";
    }
    cout << endl;
    return 0;
}
