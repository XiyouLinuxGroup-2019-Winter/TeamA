/*************************************************************************
	> File Name: fork4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 02时22分59秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
    pid_t pid;
    char *message;
    int n;
    pid = fork();
    if (pid < 0)
    {
    perror("fork failed");
    exit(1);
    }
    if (pid == 0) 
    {
        message = "This is the child\n";
        n = 6;
    } 
    else 
    {
        message = "This is the parent\n";
        n = 3;
    }
    for(; n > 0; n--)
    {
        printf(message);
        sleep(1);
    }
}
