#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>
void handler_sigtime(int signo)
{
    switch (signo)
    {
    case SIGALRM:
        printf("recv SIGALAM\n");
        break;
    case SIGPROF:
        printf("recv SIGPROF\n");
    default:
        break;
    }
}
int main()
{
    struct itimerval value;
    struct itimerval ovalue;
    signal(SIGALRM,handler_sigtime);
    signal(SIGPROF,handler_sigtime);
    value.it_value.tv_sec=1;//0则无
    value.it_value.tv_usec=0;
    value.it_interval.tv_sec=1;//0则一次
    value.it_interval.tv_usec=0;
    setitimer(ITIMER_REAL,&value,NULL);
    setitimer(ITIMER_PROF,&value,NULL);
    while(1)
    {   
        // sleep(3);
        struct itimerval value2;
        getitimer(SIGALRM,&value2);
        printf("%ld\n",value2.it_interval.tv_sec);   

        printf("%ld\n",value2.it_value.tv_sec);
    }

}
//93858353275600
//139995530268680