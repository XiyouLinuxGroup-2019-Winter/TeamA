/*************************************************************************
	> File Name: ioctl_tyy.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月06日 星期五 17时31分29秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
//使用TIOCGWINSZ命令获得终端设备的窗口大小
int main(void)
{
    struct winsize size;
    if (isatty(STDOUT_FILENO) == 0)
    exit(1);
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size)<0) 
    {
        perror("ioctl TIOCGWINSZ error");
        exit(1);
    }
    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}
