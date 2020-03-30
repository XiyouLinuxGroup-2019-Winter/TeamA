/*************************************************************************
	> File Name: pipe_lswc-l.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月30日 星期一 20时25分23秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc,char* argv[])
{
    //先创建管道,在fork子进程，父进程执行ls,关闭读端，子进程执行wc,关闭写端
    int fd[2];
    int ret;
    pid_t pid;

    ret=pipe(fd);
    if(ret==-1)
    {
        perror("pipe error");
        exit(1);
    }

    pid=fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(2);
    }
    else if(pid==0)
    {
        close(fd[0]);//关闭读
        dup2(fd[1],STDOUT_FILENO);
        //sleep(1);
        execlp("ls","ls",NULL);//ls写到标准输出上
    }
    else if(pid>0)
    {
        close(fd[1]);//关闭写端
        dup2(fd[0],STDIN_FILENO);
        execlp("wc","wc","-l",NULL);//wc标准输入读
    }

    
}
