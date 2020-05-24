#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void child_rw_pipe(int readfd,int writefd)
{
    char* message1="from child process\n";
    write(writefd,message1,strlen(message1)+1);

    char message2[100];
    read(readfd,message2,100);
    printf("child process read from pipe:%s",message2);
}
void parent_rw_pipe(int readfd,int writefd)
{
    char* message1="from parent process\n";
    write(writefd,message1,strlen(message1)+1);
    char message2[100];

    read(readfd,message2,100);
    printf("parent process read from pipe:%s",message2);
}
int main()
{
    int pipe1[2],pipe2[2];
    pid_t pid;
    int stat_val;

    printf("realize full-duplex communication :\n\n");

    pipe(pipe1);
    pipe(pipe2);

    pid=fork();
    switch (pid)
    {
    case 0:
        close(pipe1[1]);
        close(pipe2[0]);
        child_rw_pipe(pipe1[0],pipe2[1]);
        exit(0);
    default:
        close(pipe1[0]);
        close(pipe2[1]);
        parent_rw_pipe(pipe2[0],pipe1[1]);
        wait(&stat_val);
        exit(0);
    }
}