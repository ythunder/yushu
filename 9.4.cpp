/*************************************************************************
	> File Name: 9.4.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月25日 星期一 17时32分48秒
    >write function that takes a pair of iterators to a vector and an int value, look for that value in the range and return a bool indicating whether it was found.
 ************************************************************************/

 bool find (vector<int> :: iterator begin, vector<int> :: iterator end, int value)
 {
     for (auto iter = begin; iter != end; ++iter) {
         if (*iter == value) {
             return true;
         }
 }

