/*************************************************************************
	> File Name: sigsfunc.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月13日 星期一 00时29分49秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void print_set(sigset_t *set)
{
    int i;
    for(i=1;i<32;i++)
    {
        if(sigismember(set,i))
            putchar('1');
        else
            putchar('0');
    }
    printf("\n");
}
int main()
{
    sigset_t set,oldset,pedset;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigaddset(&set,SIGQUIT);
    sigaddset(&set,SIGKILL);//９号信号无法屏蔽
    sigaddset(&set,SIGBUS);


    sigprocmask(SIG_BLOCK,&set,&oldset);

    while(1){
        
    sigpending(&pedset);
    print_set(&pedset);
    sleep(1);
    }
}

