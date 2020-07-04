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
int var=100;
int main(int argc,char*argv[])
{
    int i;
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid==0)//子进程创建成功
    {
        //var=200;
        printf("I am child pid=%d,parent pid=%d\n",getpid(),getppid());
        printf("child var=%d\n",var);
    }
    else if(pid>0)//父进程
    {
        var=288;
        printf("parent var=%d\n",var);
        printf("I am parent pid=%d,getppid=%d\n",getpid(),getppid());//a.out的祖先就是bash
    }
}

