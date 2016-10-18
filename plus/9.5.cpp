/*************************************************************************
	> File Name: 9.4.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月25日 星期一 17时32分48秒
    > Rewrite the previous program to return an iterator to the requested element, Note that program must handle the case where the element is not found .
*****************************************************************
*******/

vector<int> :: iterator find (vector<int> :: iterator begin, vector<int> :: iterator end, int value)
{
    for (auto iter = begin; iter != end; ++ iter)
    {
        if (*iter == value) 
        {
            return iter;
        }
    }
    return end;
}
