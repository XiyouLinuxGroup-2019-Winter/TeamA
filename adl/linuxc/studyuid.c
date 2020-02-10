#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
extern int errno;
int main()
{
    int fd;
    printf("uid study:\n");
    printf("progress's uid =%d ,euid =%d\n",getuid(),geteuid());
    unsigned uid_before=getuid();
     if(setuid(0)==-1)
        perror("fail");
     printf("progress's uid =%d ,euid =%d\n",getuid(),geteuid());
    if((fd=open("test.c",O_RDWR))==-1){
        printf("open failure ,errno is %d %s\n",errno,strerror(errno));
        exit(1);
    }else{
        printf("open succeseefully");
    }
    close(fd);
    
    setuid(uid_before);
    if((fd=open("test.c",O_RDWR))==-1){
        printf("open failure ,errno is %d %s\n",errno,strerror(errno));
        exit(1);
    }else{
        printf("open succeseefully");
    }
    close(fd);
    exit(0);
}