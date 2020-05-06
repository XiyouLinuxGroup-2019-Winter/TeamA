/*************************************************************************
	> File Name: daemon.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月19日 星期日 00时35分41秒
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{
    pid_t pid;
    int ret,fd;
    pid=fork();
    if(pid>0)
        exit(0);

    pid=setsid();
    
    chdir("/home/taciturn-wu/");
    umask(0022);//755
    close(STDIN_FILENO);//关闭文件描述符0
    open("/dev/null",O_RDWR);//fd---->0
    dup2(fd,STDOUT_FILENO);//重定向到stdout和stderr
    dup2(fd,STDERR_FILENO);
    while(1);
}
