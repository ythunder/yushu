/*************************************************************************
	> File Name: json_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月22日 星期三 17时24分08秒
 ************************************************************************/

#include <iostream>
#include <json/json.h>
#include "Json.cpp"
#include <memory>
int main()
{
    std::string method = "get";
    std::string key = "yun";
    std::string value = "yunting";
    
    std::shared_ptr<JSon> a;

    std::string reslult = a->ConstructJson(method, key, value);

    std::cout << reslult << std::endl;

    return 0;
}
