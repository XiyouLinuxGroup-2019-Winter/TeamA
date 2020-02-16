#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int fd;
    if((fd=open("test_signal.txt",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))==-1)
    {
        printf("open wrong\n");
    }
    printf("recv SIGINT\n");
   char s[]="recv SIGINT\n";
    if(write(fd,s,strlen(s))!=strlen(s))
        printf("wrong in write\n");//perror("wrong\n");
    close(fd);
}