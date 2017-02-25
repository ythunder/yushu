/*************************************************************************
	> File Name: Message.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月22日 星期三 02时19分21秒
 ************************************************************************/

#include <iostream>
#include "Connection.h"
#include <memory>
#include <stdio.h>
#include <iterator>
#include <json/json.h>
#include "Json.h"

class Message
{
public:
    void test(std::shared_ptr<Connection> c , Buffer* b)
    {
        int start[4] = {8,32, 64, 128};
        
        std::string recvString;
        
        int len = b -> readableSize();    //缓冲区中字节数
        recvString.assign(b->getReadPeek(), b->getReadPeek()+len); //读出来
        b->moveReadIndex(len);         //移动可写指针

        JSon recvJson(recvString);
        Json::Value resultValue = recvJson.ParseJsonFromString();  //转换为JSON格式
  
        //处理我的数据
        if(resultValue["method"].asString() == "get") {
            //get 请求
        }
        else if(resultValue["method"].asString() == "set") {
            //set请求
            std::string key = resultValue["key"].asString();
            std::string value = resultValue["value"].asString();

            int len_value = strlen(value);
            
            for(int i=0; i<4; i++)
            {
                if(len_value > start[i]) {
                    break;
                }
            }
            
        }

    }


};
