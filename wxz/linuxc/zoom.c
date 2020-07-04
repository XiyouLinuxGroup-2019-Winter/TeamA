/*************************************************************************
	> File Name: orphan.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 23时26分01秒
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
    else if(pid==0)//子进程创建成功
    {
        printf("---child, my parent=%d,going to sleep 10s\n",getppid());
        sleep(10);
        printf("------child die------\n");
    }
    else if(pid>0)//父进程创建成功
    {
        while(1)
        {
            printf("I am parent ,pid =%d,myson=%d\n",getpid(),pid);
            sleep(1);
        }
    }
}

