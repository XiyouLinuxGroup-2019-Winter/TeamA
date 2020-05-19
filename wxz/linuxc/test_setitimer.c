/*************************************************************************
	> File Name: test_setitimer.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月18日 星期一 00时49分45秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler_sigtime(int signo)
{
    switch(signo)
    {
        case SIGALRM:
            printf("recv SIGALRM\n");
            break;
        case SIGPROF:
            printf("recv SIGPROF\n");
            break;
        default:
            break;
    }
}
int main()
{
    struct itimerval value;
    signal(SIGALRM,handler_sigtime);
    signal(SIGPROF,handler_sigtime);

    value.it_value.tv_sec=1;

    value.it_value.tv_usec=0;
    value.it_interval.tv_sec=5;
    value.it_interval.tv_usec=0;

    setitimer(ITIMER_REAL,&value,NULL);
    setitimer(ITIMER_PROF,&value,NULL);

    while(1)
        ;
}
