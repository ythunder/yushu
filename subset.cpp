/*************************************************************************
	> File Name: subset.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月31日 星期一 21时56分11秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm.h>

using std::vector;

class Solution {
    public:
    vector<vector<int> > subsets(vector<int> &S) {
                vector<vector<int> > res;
                vector<int> emp;
                res.push_back(emp);
                sort(S.begin(), S.end());
                if(S.size() == 0) return res;
        for(vector<int>::iterator ind = S.begin(); ind < S.end(); ++ind){
                        int size = res.size();
            for(int i = 0; i < size; ++i){
                                vector<int> v;
                for(vector<int>::iterator j = res[i].begin(); j < res[i].end(); ++j){
                                       v.push_back(*j);
                                    
                }
                                v.push_back(*ind);
                                res.push_back(v);
                            
            }
                    
        }
                return res;
            
    }

};

int main()
{
    std::vector<int> a{1,2,3};
    Solution so.subset(a);
    return 0;
}
