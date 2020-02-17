#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>
#include<assert.h>
#define FIFO_READ "readfifo"
#define FIFO_WRITE "writefifo"
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
        printf("cant create fifo %s because %s",FIFO_READ,strerror(errno));
        exit(1);
    }
    #endif
    umask(0);
    wfd=open(FIFO_WRITE,O_WRONLY);//打开写端
    if (wfd==-1)
    {
        printf("open fifo %s error :%s",FIFO_WRITE,strerror(errno));
        exit(1);
    }
    while((rfd=open(FIFO_READ,O_RDONLY))==-1)//停在读端
    {
        puts("等待客户连接中");
        sleep(1);
    }
    while(1)
    {   
        printf("Server: ");
        printf("%s\n",strerror(errno));
        fgets(buf,BUF_SIZE,stdin);
        printf("%s\n",strerror(errno));
        buf[strlen(buf)-1]='\0';
        if(strncmp(buf,"quit",4)==0)
        {
            close(wfd);
            unlink(FIFO_WRITE);
            close(rfd);
            exit(0);
        }
        // int len1;
        // if(len1=write(wfd,buf,strlen(buf)))
        //     perror("write error");
        assert(write(wfd,buf,strlen(buf))==strlen(buf));
   //     printf("len1=%d\n",len1);
        printf("%s\n",strerror(errno));
        len=read(rfd,buf,BUF_SIZE);
        if(len>0)
        {
            buf[len]='\0';
            printf("Client :%s\n",buf);
        }
        printf("%s\n",strerror(errno));
    }
}