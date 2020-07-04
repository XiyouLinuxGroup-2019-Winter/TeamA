/*************************************************************************
	> File Name: my_signal.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月11日 星期六 03时14分55秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
void handler_sigint(int signo)
{
    printf("recv SIGINT\n");
}
int main()
{
    //安装信号处理函数
    signal(SIGINT,handler_sigint);
    while(1)
    ;
}
