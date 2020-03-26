/*************************************************************************
	> File Name: my_cp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 18时47分52秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>


#define N 1
int main(int argc,char* argv[])
{
    char buf[N];

    int n=0;
    int fd1=open("mmp_test",O_RDONLY);
    if(fd1==-1)
    {
        perror("open argv[1] error");
        exit(1);
    }
    
    int fd2=open("mmp_test.cp1",O_RDWR | O_CREAT | O_TRUNC,0664);
    if(fd2==-1)
    {
        perror("open argv[2] error");
        exit(1);
    }
    while((n=read(fd1,buf,N))!=0)
    {
        if(n<0)
        {
            perror("read error");
            break;
        }
        write(fd2,buf,n);
    }


    close(fd1);
    close(fd2);
}
