/*************************************************************************
	> File Name: fork2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 17时19分25秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    char* msg;
    int k;

    printf("Process Creation Study\n");
    pid=fork();
    switch(pid)
    {
        case 0:
        msg="Child Process is running\n";
        k=3;
        break;
        case -1:
        perror("Process Creation failed\n");
        break;
        default:
        msg="Parents Process is running";
        k=5;
        break;
    }
    while(k>0)
    {
        puts(msg);
        sleep(1);
        k--;
    }
    exit(0);
}
