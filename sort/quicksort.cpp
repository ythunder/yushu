/*************************************************************************
	> File Name: quicksort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月23日 星期四 02时05分32秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>


class Solution
{
public:
    std::vector<int> quicksort(std::vector<int> left, std::vector<int> right, int centor)
    {
        if(left.size()<=1 && right.size() = 1) return ;

        std::vector<int>::iterator frontIt = vec.begin();
        std::vector<int>::iterator backIt = vec.end()-1;

        int vecLen = vec.size();

        while(frontIt<backIt && *frontIt < centor) frontIt++;
        while(backIt>frontIt && *backIt > centor) backIt++;

        std::vector<int> vecLeft;
        
        std::vector<int> vecRight;
    

        quicksort();    

        return vecLeft.insert();
    }
};


int main()
{
    Solution a;
    std::vector<int> b{1,6,2,3,5,9,4,0};
    a.quicksort(b);

    std::vector<int>::iterator it = b.begin();
    for(it; it!=b.end(); ++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}
