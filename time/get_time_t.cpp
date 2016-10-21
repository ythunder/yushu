/*************************************************************************
	> File Name: get_time_t.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 20时35分52秒
 ************************************************************************/

/*
struct tm {
            int tm_sec;     // 秒 – 取值区间为[0,59] 
            int tm_min;     //分 - 取值区间为[0,59] 
            int tm_hour;    // 时 - 取值区间为[0,23] 
            int tm_mday;    // 一个月中的日期 - 取值区间为[1,31] 
            int tm_mon;     // 月份（从一月开始，0代表一月） - 取值区间为[0,11] 
            int tm_year;    // 年份，其值等于实际年份减去1900 
            int tm_wday;    // 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 
            int tm_yday;    // 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 
            int tm_isdst;   //夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负
                                                                                    
};

*/


#include <iostream>
#include "time.h"
#include "stdio.h"

int main()
{
    time_t It;
    It = time(NULL);
    printf("The Calendar Time now is %d\n", It);   //得到运行程序时的日历时间，从1970年到现在的秒数

    struct tm* ptr = gmtime(&It);     //将日历时间转换为世界标准时间
    
    std::cout << ptr->tm_hour << std::endl;

    ptr = localtime(&It);     //将日历时间转换为本地标准时间
    std::cout << ptr->tm_hour << std::endl;

    printf(asctime(ptr));    //将标准时间转换为固定格式

    printf(ctime(&It));   //将日历时间转换为固定格式

    time_t t = mktime(ptr);

    printf("%d\n", t);

    return 0;
}


