/*************************************************************************
	> File Name: kill.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月11日 星期六 18时10分02秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
int main(int argc,char* argv[])
{
    pid_t pid=fork();
    if(pid>0)
    {
        while(1)
        {
            printf("parent,pid=%d\n",getpid());
            sleep(1);       
        
        }
    }
    else if(pid==0)
    {
        //sleep(2);
        printf("child pid=%d\n,ppid=%d\n",getpid(),getppid());
        sleep(10);
        kill(getppid(),SIGKILL);
        //while(1);
    }
}
