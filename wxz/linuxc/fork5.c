/*************************************************************************
	> File Name: fork5.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 16时06分24秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char*argv[])
{
    int i;
    //for(i=0;i<5;i++)
        pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid==0)
    {
        printf(",,,,,,,child is Created,pid=%d,parent pid=%d\n",getpid(),getppid());
    }
    else if(pid>0)
    {
        printf("...parent process:my child is %d,my pid:%d,my parent pid:%d\n",pid,getpid(),getppid());
    }
}

