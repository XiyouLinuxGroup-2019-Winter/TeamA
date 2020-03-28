/*************************************************************************
	> File Name: dup.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月27日 星期五 20时23分13秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
    int fd1=open(argv[1],O_RDWR);

    int fd2=open(argv[2],O_RDWR);
    int fdret=dup2(fd1,fd2);
    
    int ret=write(fd2,"1234567",7);
    printf("fdret:%d",fdret);
    printf("tet =%d\n",ret);

    dup2(fd1,STDOUT_FILENO);

    printf("..........886\n");
}
