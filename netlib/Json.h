/*************************************************************************
	> File Name: Json.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月22日 星期三 17时10分57秒
 ************************************************************************/
#pragma once

#include <iostream>
#include <json/json.h>

class JSon
{
public:
    JSon()
    {
    }

    JSon(std::string source_string)
        :str_(source_string)
    {
    }


    //构建JSON串,将传入信息构造成JSON对象，转换成字符串
    std::string ConstructJson(std::string method, std::string key, std::string value)
    {
        Json::Value arrayObj;   //构建对象
        Json::Value method_item,key_item, value_item;
        
        method_item["method"] = method;    //将数据逐个追加
        arrayObj.append(method_item);

        key_item["key"] = key;
        arrayObj.append(key_item);

        value_item["value"] = value;
        arrayObj.append(value_item);

        Json::FastWriter writer;    //将JSON对象转换为字符串
        std::string StringObj = writer.write(arrayObj);

        std::string resultString;    //处理两头得[  ]
        resultString.assign(StringObj.begin()+1, StringObj.end()-2);
        
        return resultString;
    }



    //将字符串解析为VALUE
    Json::Value ParseJsonFromString()
    {
        Json::Value root;
        if(reader_.parse(str_, root)) {
            std::string method_string = root["method"].asString();
            std::string key_string = root["key"].asString();
            std::string value_string = root["value"].asString();
        }
        return root;
    }
    

private:
    std::string str_;     //存储字符串
    Json::Reader reader_;
};


