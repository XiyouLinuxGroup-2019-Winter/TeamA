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
    else if(pid==0)
    {
        while(1)
        {
            printf("I am child, my parent pid=%d\n",getppid());
            sleep(1);
        }
    }
    else if(pid>0)
    {
        printf("I am parent ,my pid is =%d\n",getpid());
        sleep(9);
        printf("----------parent going to die--------\n");
    }
}

