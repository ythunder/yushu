/*************************************************************************
	> File Name: 10_9.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 11时42分58秒
    > Implement your own version of elimDups.Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std :: vector;
using std :: string;
using std :: ostream;
using std :: cout;
using std :: endl;
using std :: sort;
using std :: unique;

template<typename Sequence> auto println(Sequence const& seq) -> std :: ostream &
{
    for (auto const& elem : seq) 
    {
        cout << elem << " ";
    }
    return cout << endl;
}

auto eliminate_duplicates(vector<string>& vs) -> vector<string> & 
{
    sort(vs.begin(), vs.end());
    println(vs);

    auto new_end = unique(vs.begin(), vs.end());
    println(vs);

    vs.erase(new_end, vs.end());
    return vs;
}

int main()
{
    vector<string> vs = {"a", "v", "a", "s", "v", "a", "a"};
    println(vs);
    println(eliminate_duplicates(vs));
}

