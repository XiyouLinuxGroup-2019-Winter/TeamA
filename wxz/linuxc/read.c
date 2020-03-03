/*************************************************************************
	> File Name: read.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月02日 星期一 15时50分55秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char buf[10];
    int n;
    n=read(STDIN_FILENO,buf,10);
    if(n<0)
    {
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDIN_FILENO,buf,n);
}
