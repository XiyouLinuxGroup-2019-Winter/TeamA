/*************************************************************************
	> File Name: catch_child.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月14日 星期二 00时26分15秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
void catch_child(int signo)
{
    pid_t wpid=wait(NULL);
    printf("--------catch child id %d\n",wpid);
}
int main()
{
    pid_t pid;
    int i;
    for(i=0;i<5;i++)
    {
        if((pid=fork())==0)
            break;
    }
    if(i==5)
    {
        struct sigaction act;
        act.sa_handler=catch_child;
        sigemptyset(&act.sa_mask);
        act.sa_flags=0;

        sigaction(SIGCHLD,&act,NULL);
        printf("I'm parent,pid=%d\n",getpid());
        while(1);
    }
    else
    {
        printf("I'm child pid=%d\n",getpid());
    }
}
