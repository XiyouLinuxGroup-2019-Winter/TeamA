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
    //先创建管道,在fork兄弟进程，兄进程执行ls,关闭读端，弟进程执行wc,关闭写端
    int fd[2];
    int ret,i,n;
    char buf[1024];
    pid_t pid;

    ret=pipe(fd);
    if(ret==-1)
    {
        perror("pipe error");
        exit(1);
    }
    for(i=0;i<2;i++)//表达式２出口，父进程使用
    {
        pid=fork();
        if(pid==0)//子进程出口
        break;
    }
    
    if(i==2)//父进程
    {
        close(fd[1]);//父进程关闭写端，留读端读取数据
        sleep(1);
        n=read(fd[0],buf,1024);//从管道中读数据
        write(STDOUT_FILENO,buf,n);
        wait(NULL);
        wait(NULL);
    }
    else if(i==0)//兄进程
    {
        
        close(fd[0]);//关闭读
        write(fd[1],"1.hello\n",strlen("1.hello\n"));
    }
    else if(i==1)//弟进程
    {
        
        close(fd[0]);//关闭读端
        write(fd[1],"2.world\n",strlen("2.world\n"));
    }

    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }

    
}
