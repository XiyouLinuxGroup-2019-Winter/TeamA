/*************************************************************************
	> File Name: getpid.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 03时32分51秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    if((pid=fork())==-1)
    {
        printf("fork error!\n");
        exit(1);
    }
    if(pid==0)
        printf("getpid return %d\n",getpid());
    exit(0);
}
