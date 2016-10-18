/*************************************************************************
	> File Name: 9.27.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 02时56分29秒
    > Write a program to find and remove the add-values elements in a forward_list<int>.
 ************************************************************************/

#include <iostream>
#include <forward_list>

using std :: forward_list;
using std :: cout;
using std :: endl;

int main()
{
    forward_list<int> flis = {1,2,3,4,5,6,7,8,9};

    auto prev = flis.before_begin();
    auto curr = flis.begin();

    while (curr != flis.end()) 
    {
        if (*curr % 2) 
        {
            curr = flis.erase_after(prev);
        }
        else 
        {
            prev = curr;
            ++ curr;
        }
    }
    for (auto l : flis) 
    {
        cout << l << " ";
    }
    cout << endl;
    return 0;
}

