#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    pid=fork();
    switch (pid)
    {
    case 0:
        printf("childruning,curpid=%d,parpid=%d\n",pid,getppid());
        break;
        break;
    case -1:
        perror("fail");
        break;
    default:
    printf("parentruning childpid=%d,parpid=%d",pid,getpid());
        break;
    }
    exit(0);
}