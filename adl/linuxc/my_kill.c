#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
int main(int argc ,char**argv)
{
    int i,j;
    int signum=SIGTERM;
    pid_t   pid;
    if(argc!=2&&argc!=4){
        printf("Usage: ./my_kill <-s signum>[PID]\n");
        exit(0);
    }
    for ( i = 1; i < argc; i++){
        if(!strcmp(argv[i],"-s")){
            signum=atoi(argv[i+1]);
            printf("%d\n",signum);
            break;
        }
    }//i==1
    if(argc==2){
        pid=atoi(argv[1]);
    }else{
        for ( j = 1; j < argc; j++)
        {
            if(j!=i&&j!=i+1){
                pid=atoi(argv[j]);
                printf("%d\n",pid);
                break;
            }
        }
        
    }
    if(kill(pid,signum)<0){
        perror("kill");
        exit(1);
    }
    return 0;
}