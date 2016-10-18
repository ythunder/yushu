/*************************************************************************
	> File Name: subset_iteration.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月18日 星期二 13时44分43秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int> > subset(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > subs(1, std::vector<int>());

        for(int i=0; i<nums.size(); i++)
        {
            int n = subs.size();
            for(int j=0; j<n; j++)
            {
                subs.push_back(subs[j]);   //复制一套
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};

int main()
{
    int aa[4] = {1,2,3,4};
    std::vector<int> num(aa, aa+sizeof(aa)/sizeof(int));
    Solution a;
    std::vector<std::vector<int> > sub = a.subset(num);
    for(std::vector<int> &i : sub)
    {
        for(int &j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
