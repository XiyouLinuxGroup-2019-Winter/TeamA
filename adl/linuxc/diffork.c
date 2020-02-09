#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int globVar=5;
int main()
{
    pid_t pid;
    int var=1,i;
    printf("fork i different with vfork\n");
    pid =vfork();
    switch (pid)
    {
    case 0:
        i=3;
        while(i-->0)
        {
           printf("CHILD\n");
          printf("pid=%d,getpid=%d,getppid=%d\n",pid,getpid(),getppid());
           globVar++;
           var++;
           sleep(1); 
        }
        printf("child globvar=%d,var=%d\n",globVar,var);
        break;
    case -1:
        perror("fail\n");
        exit(0);
    default:
        i=5;
        while(i-->0)
        {
                printf("parent\n");
                printf("pid=%d,getpid=%d,getppid=%d\n",pid,getpid(),getppid());
                globVar++;
                var++;
                sleep(1);
        }
            printf("parent glovar%d var=%d\n",globVar,var);
            exit(0);
    }
}