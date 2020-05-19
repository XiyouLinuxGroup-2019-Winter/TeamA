/*************************************************************************
	> File Name: simulate_ping.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 19时28分18秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>
void send_ip()
{
    printf("send s icmp echo request packet\n");
}

void recv_ip()
{
    while(1)
        ;
}
void handler_sigalarm(int signo)
{
    send_ip();
    alarm(2);
}
int main()
{
    signal(SIGALRM,handler_sigalarm);

    raise(SIGALRM);
    recv_ip();
}

