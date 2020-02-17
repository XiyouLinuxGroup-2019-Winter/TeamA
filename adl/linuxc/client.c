#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>

#define FIFO_READ "writefifo"
#define FIFO_WRITE "readfifo"
#define BUF_SIZE 1024
int main()
{
    int wfd,rfd;
    char buf[BUF_SIZE];
    int len;
    umask(0);
    #if 0
    if(mkfifo(FIFO_WRITE,__S_IFIFO|0666))
    {
        printf("cant create fifo %s because %s",FIFO_WRITE,strerror(errno));
        exit(1);
    }
    umask(0);
    #endif

    while((rfd=open(FIFO_READ,O_RDONLY))==-1)//打开读端//如果开始没有这个文件,也就是没有连接。但之后就不用了因为文件已存在
    {
        puts("等待服务端连接中");
        sleep(1);
    }
    wfd=open(FIFO_WRITE,O_WRONLY);//打开写端
    if (wfd==-1)
    {
        printf("open fifo %s error :%s",FIFO_WRITE,strerror(errno));
        exit(1);
    }
    while(1)
    {
        puts("there>1");
        len=read(rfd,buf,BUF_SIZE);
        puts("there>2");
        if(len>0)
        {
            buf[len]='\0';
            printf("Server :%s\n",buf);
        }
        printf("Client: ");
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
    }
}