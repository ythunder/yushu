/*************************************************************************
	> File Name: 10_9.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 11时42分58秒
    > Write a program that uses stable_sort and isShorter to sort a vector to your version of elomDups. Print the vector to verify that your program is correct.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

using std :: vector;
using std :: string;
using std :: ostream;
using std :: cout;
using std :: endl;
using std :: sort;
using std :: unique;
using std :: list;
using std :: stable_sort;

template <typename Sequence> 
inline ostream& println(Sequence const& seq)
{
    for (auto const& elem : seq)
    {
        cout << elem << " ";
    }
    return cout;
}

inline bool is_shorter(string const& lhs, string const& rhs)
{
    return lhs.size() < rhs.size();
}

void elimdups(vector<string>& vs)
{
    sort(vs.begin(), vs.end());
    auto end_unique = unique(vs.begin(), vs.end());
    vs.erase(end_unique, vs.end());
}

int main()
{
    vector<string> vec{"fox", "jumps", "the", "fox", "the", "re", "qw"};
    elimdups(vec);
    stable_sort(vec.begin(), vec.end(), is_shorter);
    println(vec);
}
