/*************************************************************************
	> File Name: exec_ps.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 23时12分47秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{
    int fd;
    fd=open("ps.out",O_WRONLY | O_CREAT|O_TRUNC,0644);
    if(fd<0)
    {
        perror("open ps.out error");
        exit(1);
    }
    dup2(fd,STDOUT_FILENO);
    execlp("ps","ps","ax",NULL);
    perror("execlp error");
}
