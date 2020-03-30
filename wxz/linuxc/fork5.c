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
        //getpid()->子进程的pid值，getppid()->父进程的pid值
        printf(",,,,,,,child is Created,pid=%d,parent pid=%d\n",getpid(),getppid());//子进程创造成功
    }
    else if(pid>0)
    {
        printf("...parent process:my child is %d,my pid:%d,my parent pid:%d\n",pid,getpid(),getppid());//bash就是一个父进程，a.out就是一个子进程
    }
}

