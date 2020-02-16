#include<stdio.h>
#include<unistd.h>

#include<signal.h>

#include<stdlib.h>
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d ",line);
    perror(err_string);
    exit(1);   
}
void hander_sigint(int signo)
{
    printf("recv SIGINT\n");
}
int main()
{
    sigset_t newmark,oldmark,pendmark;
    if(signal(SIGINT,hander_sigint)==SIG_ERR){
        my_err("signal",__LINE__);
    }
    sleep(10);
    sigemptyset(&newmark);
    sigaddset(&newmark,SIGINT);
    if(sigprocmask(SIG_BLOCK,&newmark,&oldmark)<0){
        my_err("sigprocmask",__LINE__);
    }else{
        printf("SIGINT blocked\n");
    }
    sleep(10);//这个时候是怎么也阻断不了sleep的,alarm在阻塞队列中，即使这里用了多次^C也只会阻塞一次，见p222.//之后是先将阻塞队列中的信号响应了再去printf("sigint unblock\n")
    if(sigpending(&pendmark)<0){
        my_err("sigpending",__LINE__);
    }
    switch (sigismember(&pendmark,SIGINT))
    {
    case 0:
        printf("SIGINT is not in pending queue\n");
        break;
    case 1:
        printf("SIGINT is in pending queue\n");
        break;
    case -1:
        my_err("sigismember",__LINE__);
        break;
    default:
        break;
    }
    if(sigprocmask(SIG_SETMASK,&oldmark,NULL)<0){//这里是恢复old
        my_err("sigprocmark",__LINE__);
    }else{
        printf("SIGINT unblocked\n");
    }
    while(1)
        ;
    return 0;
}