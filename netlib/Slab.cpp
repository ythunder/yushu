/*************************************************************************
	> File Name: Slab.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月25日 星期六 00时29分57秒
 ************************************************************************/

#include "Slab.h"

//构造函数仅初始化数据
Slab::Slab(int id, int slabsize, int chunksize, char* addrspace)
    :slabId_(id),
    slabSize_(slabsize),
    chunkSize_(chunksize),
    slabSpace_(addrspace)
    {
        chunkCount_ = slabSize_/chunkSize_;   
    }

    
void 
Slab::initSpace()
{
    char* temp = slabSpace_;

    for(int i=0; i<chunkCount_; ++i)
    {
        Slot_.push_back(temp);
        temp += chunkSize_;
    }
}


char*
Slab::getSlotNode()
{
    char* temp = Slot_.front();
    Slot_.pop_front();
    return temp;
}


void 
Slab::setRluNode_(char *ptemp)
{
    Rlu_.push_back(ptemp);
}

//回收数据处理
