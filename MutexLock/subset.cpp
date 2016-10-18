/*************************************************************************
	> File Name: subset.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月17日 星期一 20时02分53秒
 ************************************************************************/

#include <iostream>
#include <vector>


void all_subset(int arr[], unsigned int size, std::vector<bool>& contains, int depth)
{
    if(depth == size)
    {
        for(int j=0; j<size; j++)
        {
            if(contains[j])
            {
                std::cout << arr[j] << " ";
            }
        }
        std::cout << std::endl;
    }
    else 
    {
        contains[depth] = false;
        all_subset(arr, size, contains, depth+1);
        contains[depth] = true;
        all_subset(arr, size, contains, depth+1);
    }
}

int main()
{
    int s[] = {1,2,3};
    int size = sizeof(s)/sizeof(int);
    std::vector<bool> contains(3,false);
    all_subset(s, 3, contains, 0);
}
