#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
    pid_t   pid;
    int stat_val=0;
    int oldpri,newpri;
    int fapri;
    pid=fork();
    switch (pid)
    {
    case 0:
        printf("child pid=%d,getpid=%d,getppid=%d\n",pid,getpid(),getppid());
        oldpri=getpriority(PRIO_PROCESS,0);
        printf("child priority=%d\n",oldpri);
                newpri=nice(2);
        printf("new   priority =%d\n",newpri);
        exit(0);
    case -1:
        perror("failed\n");
        break;
    default:
    printf("parent pid=%d,getpid=%d,getppid=%d\n",pid,getpid(),getppid());
   //     oldpri=getpriority(PRIO_PROCESS,0);
//printf("parent old priority =%d\n",oldpri);

        break;
    }
    wait(&stat_val);
    exit(0);
}
//fail!