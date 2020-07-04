/*************************************************************************
	> File Name: sigaction.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月13日 星期一 01时57分18秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void sig_cath(int signo)
{
    if(signo==SIGINT)
    {
        printf("catch you %d\n",signo);
        sleep(10);
    }
    if(signo==SIGQUIT)
        printf("-------catch you %d\n",signo);
}
int main()
{
    struct sigaction act,oldact;
    act.sa_handler=sig_cath;//设置回调函数名
    sigemptyset(&act.sa_mask);//设置屏蔽字,当sig_cath工作时有效，清空sa_mask屏蔽字
    act.sa_flags=0;//设置默认值

    sigaction(SIGINT,&act,&oldact);//注册信号捕捉函数
    sigaction(SIGQUIT,&act,&oldact);
    while(1);
}
