#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

void hander_sigint(int signo)
{
    printf("recv SIGINT\n");
}
int main()
{
    sigset_t newmask,oldmask,pendmask;
    if(signal(SIGINT,hander_sigint)==SIG_ERR)
    {
        my_err("signal",__LINE__);
    }
    sleep(10);

    sigemptyset(&newmask);
    sigaddset(&newmask,SIGINT);

    if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
        my_err("sigprocmask",__LINE__);
    else
        printf("SIGINT blocked\n");

    sleep(10);

    if(sigpending(&pendmask)<0)
        my_err("sigpending",__LINE__);
    
    switch(sigismember(&pendmask,SIGINT))
    {
        case 0:
            printf("SIGINT is not in pending queue\n");
            break;
        case 1:
            printf("SIGINT is in pending queue\n");
            break;
        case -1:
            my_err("sigismemeber",__LINE__);
            break;
        default:
            break;

        if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
            my_err("sigprocmask",__LINE__);
        else
            printf("SIGINT unblocked\n");

        while(1)
            ;
        
    }
    
}