#include "MemoryCache.h"

int main()
{
    EventLoop loop;
    EventLoopThread inspectThread;
    MemoryCacheServer::Options Options;  //指定使用协议

    //处理参数
    
    MemoryCacheServer server(&loop, Options);
    server.setThreadNum();

    server.start();
    loop.loop();
    return 0;
}
