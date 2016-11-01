#include "Timestamp.h"
#include<stdio.h>
using namespace muduo;

int main()
{
        Timestamp timeStamp=Timestamp::now();
        printf("it's %ld microseconds from Epoch\n", timeStamp.microSecondsSinceEpoch());
        //string str= timeStamp.toString();
        string str = timeStamp.toFormattedString(true);
        printf("string format is %s\n", str.c_str());
        return 0;

}
