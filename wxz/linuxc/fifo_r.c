/*************************************************************************
	> File Name: fifo_W.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月31日 星期二 01时11分36秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc,char* argv[])
{
    int fd,len;
    char buf[4096];
    if(argc<2)
    {
        printf("enter like this:./a.out\n");
        return -1;
    }
    fd=open(argv[1],O_RDONLY);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    while(1)
    {
        len=read(fd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
        sleep(3);//
    }
    close(fd);
}
