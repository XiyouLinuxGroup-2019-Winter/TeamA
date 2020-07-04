#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define FIFO_READ "readfifo"
#define FIFO_WRITE "writefifo"
#define BUF_SIZE 1024

int main()
{
    int wfd,rfd;
    char buf[BUF_SIZE];
    int len;

    umask(0);
    mkfifo(FIFO_WRITE,S_IFIFO|0666);
    umask(0);
    wfd=open(FIFO_WRITE,O_WRONLY);
    while((rfd=open(FIFO_READ,O_RDONLY))==-1)
        sleep(1);
    
    while(1)
    {
        printf("Server:");
        fgets(buf,BUF_SIZE,stdin);
        buf[strlen(buf)-1]='\0';
        if(strncmp(buf,"quit",4)==0)
        {
            close(wfd);
            unlink(FIFO_WRITE);
            close(rfd);
            exit(0);
        }
        write(wfd,buf,strlen(buf));
        len=read(rfd,buf,strlen(buf));

        if(len>0)
        {
            buf[len]='\0';
            printf("Clinet:%s\n",buf);
        }
    }
}