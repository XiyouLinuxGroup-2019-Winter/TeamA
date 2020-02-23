#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
void handler_sigint(int signo)
{   int fd;
    if((fd=open("test_signal.txt",O_RDWR|O_APPEND,S_IRWXU))==-1)
    {
        printf("open wrong\n");
    }
    printf("recv SIGINT\n");
   char s[]="recv SIGINT\n";
    if(write(fd,s,strlen(s))!=strlen(s))
        printf("wrong in write\n");//perror("wrong\n");
    close(fd);
}
int main()
{
  //  printf("%d\n",getpid());   
   signal(SIGINT,handler_sigint);
    while(1)
    ;
    return 0;
}