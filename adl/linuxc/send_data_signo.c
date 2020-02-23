#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
int main(int argc ,char **argv)
{
    union sigval value;
    int signum=SIGTERM;
    pid_t pid;
    int i;
    value.sival_int =0;
    if(argc!=3&&argc!=5&&argc!=7){
        printf("./a.out <-d data><-s sigum>[-p][data]\n");
        exit(1);
    }
    for ( i = 0; i < argc; i++)
    {
        if(!strcmp(argv[i],"-d")){
            value.sival_int =atoi(argv[i+1]);
            continue;
        }
        if(!strcmp(argv[i],"-s")){
            signum=atoi(argv[i+1]);
            continue;
        }
        if(!strcmp(argv[i],"-p")){
            pid=atoi(argv[i+1]);
            continue;
        }
    }
    if(sigqueue(pid,signum,value)<0){
        perror("sigqueue");
        exit(1);
    }
    return 0;
}