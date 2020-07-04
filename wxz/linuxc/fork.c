/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 17时10分18秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    printf("Process Creation Study\n");

    pid=fork();
    switch(pid)
    {
        case 0:
        printf("Child Process is running,Curpid is %d,parentPid is %d\n",pid,getppid());
        break;
        case -1:
        perror("Process creation failed\n");
        break;
        default :
        printf("Parent Process is running,Childpid is %d,parentPid is %d\n",pid,getpid());
        break;
    }
    exit(0);
}
