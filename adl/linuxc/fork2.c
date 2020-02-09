#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    char*msg;
    int k ;
    pid=fork();
    switch (pid)
    {
    case 0:
        msg="child ";
        k=3;
        break;
    case -1:
        perror("failed");
    default:
        msg="parent";
        k=5;
        break;
    }
    while (k)
    {
        puts(msg);
        sleep(1);
        k--;
    }
    exit(0);   
}

