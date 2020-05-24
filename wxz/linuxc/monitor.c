#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int arg,char* argv[],char** environ)
{
    int fd[2];
    pid_t pid;
    int stat_val;

    if(arg<2)
    {
        printf("wrong parameters\n");
        exit(0);
    }
    pipe(fd);
    pid=fork();

    switch (pid)
    {
    case 0:
        close(0);
        dup(fd[0]);
        execve("ctrlprocess",(void*)argv,environ);
        exit(0);
    default:
        close(fd[0]);
        write(fd[1],argv[1],strlen(argv[1]));
        break;
    }
    wait(&stat_val);
    exit(0);
}