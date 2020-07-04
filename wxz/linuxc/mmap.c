/*************************************************************************
	> File Name: mmp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月31日 星期二 19时40分11秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
int main(int argc,char* argv[])
{
    char* p=NULL;
    int fd;
    fd=open("testmap",O_RDWR| O_CREAT|O_TRUNC,0644);

    /*lseek(fd,10,SEEK_END);
    write(fd,"\0",1);*/
    ftruncate(fd,20);
    int len=lseek(fd,0,SEEK_END);

    p=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p==MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    //使用p对文件进行读写操作
    strcpy(p,"hello mmap");//写操作
    printf("........%s\n",p);
    int ret=munmap(p,len);
    if(ret==-1)
    {
        perror("munmap error");
        exit(2);
    }
}
