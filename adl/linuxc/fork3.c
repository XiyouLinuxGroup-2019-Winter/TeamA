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
        while(1){
            printf(" ~~~PID:%d,PARENTID%d\n",getpid(),getppid());
            sleep(3);
        }
    case -1:
    perror("fail    ");
    
    default:
    printf("i am parent process my pid is%d",getpid());
        exit(0);
    }
    return 0;
}