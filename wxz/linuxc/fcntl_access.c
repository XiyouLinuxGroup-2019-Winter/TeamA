/*************************************************************************
	> File Name: fcntl_access.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月01日 星期日 22时02分38秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
//自定义的错误处理函数
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line: %d",line);
    perror(err_string);
    exit(1);
}
int main()
{
    int ret;
    int access_mode;
    int fd;

    if((fd=open("example_64",O_CREAT |O_TRUNC |O_RDWR,S_IRWXU))==-1)
        my_err("open",__LINE__);

    //设置文件打开方式
    if((ret=fcntl(fd,F_SETFL,O_APPEND))<0)
        my_err("fcntl",__LINE__);
    
    //获取文件打开方式
    if(ret=fcntl(fd,F_GETEL,0)<0)
        my_err("fcntl",__LINE__);

    access_mode=ret &O_ACCMODE;
    if(access_mode==O_RDONLY)
        printf("example_64 access_mode: read only");
    else if(access_mode==O_WRONLY)
        printf("example_64 access_mode : write only");
    else if(access_mode==O_RDWR)
        printf("example_64 access_mode: read +write");



    if(ret & O_APPEND)
        printf(" , append");
    if(ret& O_NONBLOCK)
        pritnf(" ,nonblock");
    if(ret & O_SYNC)
        printf(" , sync");

    printf("\n");
    
}
