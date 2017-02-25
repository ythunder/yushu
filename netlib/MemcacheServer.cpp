/*************************************************************************
	> File Name: MemcacheServer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月25日 星期六 12时43分43秒
 ************************************************************************/

#include "MemcacheServer.h"
#include "Json.h"
#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <json/json.h>
#include "callback.h"
#include "Connection.h"
#include "Message.cpp"
#include "Slab.h"
#include <string.h>
#include <utility>

MemcacheServer::MemcacheServer(std::string ip, int port, int number, int slabcount)
    :acceptor_(new Acceptor(ip, port, number)),
    memPtr_(new char[1024]),
    slabCount_(slabcount)
    {
        Message mess;
        
        acceptor_->setMessageCallback(std::bind(&MemcacheServer::test, this, std::placeholders::_1, std::placeholders::_2));
    
    }

MemcacheServer::~MemcacheServer()
{
    delete [] memPtr_;
}


void
MemcacheServer::initSlabSpace()
{
    int start[4] = {8, 32, 64, 128};
    int slab_count = getSlabCount();

    char* temp = getMemPtr();

    for(int i=0; i<slab_count; ++i)
    {
        vecSlab_.push_back(std::shared_ptr<Slab>(new Slab(i+1, 256, start[i], temp)));
        temp += 256;
    }
}


void 
MemcacheServer::storeData(int slabId,  std::string key, std::string value)
{
    std::vector<std::shared_ptr<Slab> > slabvec = getSlabVec();
    
    std::shared_ptr<Slab> finalslab = slabvec.at(slabId);

    char* ptemp = finalslab->getSlotNode();

    //存储数据
    memcpy(ptemp, value.c_str(), value.size());

    hashMap_.insert(std::pair<std::string, char*>(key, ptemp));
    //添加到hashmap   
    finalslab->setRluNode_(ptemp);
    
}


void 
MemcacheServer::test(std::shared_ptr<Connection> c , Buffer* b)
{
    int start[4] = {8, 32, 64, 128};
        
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

        int len_value = value.size();
            
        int i;
        for(i=0; i<4; i++)
        {
            if(len_value < start[i]) {
                break;
            }
        }
        storeData(i, key, value);  
    }
}


void
MemcacheServer::memcacheServerStart()
{
    acceptor_->start();
}
