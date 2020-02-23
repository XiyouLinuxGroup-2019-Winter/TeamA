#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
    int oldfd;
    int fd2;
    int fd;
    int t;
    char*buf="test\n";
    getchar();
    if((oldfd=open("text.txt",O_RDWR|O_CREAT,0644))==-1){
        printf("error\n");
        exit(-1);
    }
    fd2=open("text2.txt",O_RDWR|O_CREAT,0644);
    
    printf("oldfd=%d\n,fd2=%d\n",oldfd,fd2);
    fd=dup2(oldfd,STDOUT_FILENO);
    if(fd==-1){
        printf("dup2 wrong \n");
        exit(-1);
    }
    printf("dup2的返回值%d\n",fd);
    printf("oldfd= %d\n",oldfd);
    t=strlen(buf);
    if(write(oldfd,buf,t)!=t){
        printf("write error");
        exit(-1);
    }
    close(fd);
    close(fd2);
    
}