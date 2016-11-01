#include "TimeZone.h"
#include "Timestamp.h"

#include <time.h>

#include <iostream>
using namespace muduo;
void PrintTm(struct tm& T)
{
        std::cout<<T.tm_year<<"-"<<T.tm_mon<<"-"<<T.tm_mday<<std::endl;
        std::cout<<T.tm_hour<<"-"<<T.tm_min<<"-"<<T.tm_sec<<std::endl;
        std::cout<<T.tm_wday<<std::endl;

}
int main()
{

        Timestamp timeStamp=Timestamp::now();
        struct tm T=TimeZone::toUtcTime(timeStamp.secondsSinceEpoch());
        PrintTm(T);

        TimeZone timeZone(8, "China");

        struct  tm T2=timeZone.toLocalTime(timeStamp.secondsSinceEpoch());
        PrintTm(T2);

        return 0;

}
