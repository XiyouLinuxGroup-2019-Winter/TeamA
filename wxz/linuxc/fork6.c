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
int main(int argc,char* argv[])
{
    int i;
    pid_t pid;
    for(i=0;i<5;i++)
    {
        if(fork()==0)
            break;
    }
    if(i==5)
    {
        sleep(5);
        printf("I;m parent\n");
    }
        //printf("I'm parent\n");
    else
    {
        sleep(i);
        printf("I'm %dth child\n",i+1);
    }
    //printf("I'm %dth child\n",i+1);
}

