/*************************************************************************
	> File Name: MemcacheServer.h
	> Author: 
	> Mail: 
	> Created Time: 2017年02月23日 星期四 13时21分57秒
 ************************************************************************/


#include "Acceptor.h"
#include <memory>
#include <map>
#include <unordered_map>

class Slab;
class MemcacheServer
{
public:

    MemcacheServer(std::string ip, int port, int number, int slabcount);

    ~MemcacheServer();

    void initSlabSpace();   //将内存初始化为Slab块

    void memcacheServerStart();   //开启服务器


    void test(std::shared_ptr<Connection> c, Buffer* b);

    //set 存储数据
    void storeData(int slabId, std::string key, std::string value);

    //get 查找数据
    void getData();

    int getSlabCount()
    {
        return slabCount_;
    }

    std::vector<std::shared_ptr<Slab> >& getSlabVec()
    {
        return vecSlab_;
    }

    char* getMemPtr()
    {
        return memPtr_;
    }
    

private:
    std::shared_ptr<Acceptor> acceptor_;   //服务器
    std::vector<std::shared_ptr<Slab>> vecSlab_;    //所有的Slab
    char* memPtr_;                       //初始化得内存
    int slabCount_;                     //Slab数量
    std::unordered_map<std::string, char*> hashMap_;               //无重复关键字的map
};

