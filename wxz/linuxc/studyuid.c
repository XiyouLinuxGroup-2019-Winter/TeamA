/*************************************************************************
	> File Name: studyuid.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 03时46分28秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
extern int errno;

int main()
{
    int fd;
    printf("uid study :\n");
    printf("Process's uid=%d,euid=%d\n",getuid(),geteuid());

    //strerror函数获取指定错误码的提示信息
    if((fd=open("test.c",O_RDWR))==-1)
    {
        printf("Open failure,errno is %d :%s\n",errno,strerror(errno));
        exit(1);
    }
    else
        printf("Open successfully\n");

    close(fd);
    exit(0);
}
