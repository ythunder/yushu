/*************************************************************************
	> File Name: Slab.h
	> Author: 
	> Mail: 
	> Created Time: 2017年02月24日 星期五 19时11分22秒
 ************************************************************************/


#include <iostream>
#include <list>

typedef char* Space;
typedef std::list<Space> Link; 

class Slab
{
public:
    Slab(int id, int chunksize, int slabsize, char *addrspace);

    ~Slab();

    void initSpace();

    char* getSlotNode();


    void setRluNode_(char *ptemp); 


    //回收数据并将回收得数据放回内存


private:

    char* slabSpace_;

    int slabId_;  //slab ID,不同大小ID不同大小
    int slabSize_;   //slab总大小

    int chunkSize_;   //每个块大小
    int chunkCount_;   //共多少块

    Link Rlu_;   //持有占据的空间
    Link Slot_;  //持有空闲空间
    
};
