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
void handler_sigint(int signo )
{
    printf("recv SIGINT\n");
}
int main()
{   sleep(10);
    sigset_t newmask,oldmask,zeromask;
    if(signal(SIGINT,handler_sigint)==SIG_ERR){
        my_err("signal",__LINE__);
    }
    sigemptyset(&newmask);
    sigemptyset(&zeromask);
    sigaddset(&newmask,SIGINT);
    if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0){
        my_err("sigprocmask",__LINE__);
    }else{
        printf("SIGINT blocked\n");
    }
    if(sigsuspend(&zeromask)!=-1){
        my_err("sigsusoend",__LINE__);
    }else{
        printf("recv a signo ,return from sigsuspend\n");
    }
/*    if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0){
        my_err("sigprocmask",__LINE__);  
    }
    pause();*/
    if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0){
        my_err("sigprocmask",__LINE__);
    }
    while(1)
    ;
}