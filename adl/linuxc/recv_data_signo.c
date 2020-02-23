#include<stdio.h>
#include<signal.h>
void handler_sigint(int signo,siginfo_t *siginfo,void *pvoid)
{
    printf("recv SIGINT,the data value is :%d \n",siginfo->si_int);
    printf("the signo=%d\n",siginfo->si_signo);
    printf("the errno=%d\n",siginfo->si_errno);
    printf("the code=%d\n",siginfo->si_code);
    printf("the pid=%d\n",siginfo->si_pid);//发送的吧
    printf("the uid=%d\n",siginfo->si_uid);
    printf("the fd=%d\n",siginfo->si_fd);
    printf("the band=%ld\n",siginfo->si_band);
    // printf("the value???=%d\n",siginfo->si_value);
}
int main()
{
    struct sigaction act;
    act.sa_sigaction =handler_sigint;
    act.sa_flags=SA_SIGINFO;
    sigaction(SIGINT,&act,NULL);
    while(1)
        ;
    return 0; 
}