#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>

#define FIFO_NAME "myfifo"
#define BUF_SIZE 1024

int main()
{
    int fd;
    char buf[BUF_SIZE]="HELLO procread,i come from process named procwrite\n";
    umask(0);
#if 0
    if(mkfifo(FIFO_NAME,__S_IFIFO|0666)==-1)
    {
        perror("mkfifo error!");
        exit(1);
    }
#endif
    if((fd=open(FIFO_NAME,O_WRONLY))==-1)
    {
        perror("mkfifo error!");
        exit(1);
    }
    write(fd,buf,strlen(buf)+1);
    close(fd);
    exit(0);
}