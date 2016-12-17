/*************************************************************************
	> File Name: open_file.c
	> Author: 
	> Mail: 
	> Created Time: 2016年12月07日 星期三 09时46分55秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char *file_name = "hello.c";
    int fp = open(file_name, O_RDONLY);
    close(fp);
    return 0;
}


