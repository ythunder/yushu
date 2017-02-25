/*************************************************************************
	> File Name: Slab_class.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月23日 星期一 09时42分54秒
 ************************************************************************/

#ifndef _SLAB_CLASS_H
#define _SLAB_CLASS_H


#define SLAB_INIT_SIZE 1024   //初始化每个slab分配1KB


class Slab 
{
    using ItemLink = std::list<Item>;
private:
    int SlabId_;
    int ChunkCount_;
    int ChunkSize_;
    list<item> slotLink_;   //存放未分配 
    list<item> rluLink_;    //存放已分配
    vector<>
};
#endif
