/*************************************************************************
	> File Name: Process.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月23日 星期四 00时39分46秒
 ************************************************************************/

#include <string>
#include <iostream>
#include <json/json.h>
#include "Json.h"
#include <memory>
#include "Connection.h"

class Process
{
public:
    Process(Json::Value value, std::shared_ptr<Connection> c) 
        :value_(value),
        conn_(c),
        fd_(conn_->get_fd())
    {
        
    }

    ~Process()
    {
    
    }


    void handleRequest()
    {
        if(getMethod() == "get") {
            //进行查找
            //返回消息
            std::cout << "get工作\n";
        }
        else if(getMethod() == "set") {
            //查找
            //找到，发送已经有了
            //未找到，加进去
            
            


            std::cout << "set工作\n";
        }
    }

    std::string getMethod()
    {
        return value_["method"].asString();
    }

    std::string getKey()
    {
        return value_["key"].asString();
    }

    std::string getValue()
    {
        return value_["value"].asString();
    }

private:
    Json::Value value_;
    int fd_;   //查询事件所属fd
    std::shared_ptr<Connection> conn_;  //查询事件所属连接
};

