/*************************************************************************
	> File Name: orphan.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 23时26分01秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc,char*argv[])
{
    int i;
    //for(i=0;i<5;i++)
        pid_t pid=fork();
    pid_t wpid;


    int status;
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid==0)
    {
        printf("---child, my parent=%d,going to sleep 10s\n",getpid());
        sleep(10);
        printf("------child die------\n");
        return 73;
    }
    else if(pid>0)
    {
        wpid=wait(&status);//如果子进程未终止，父进程阻塞在这个函数上
        //wpid=wait(NULL);//不关心子进程结束原因
        if(wpid==-1)
        {
            perror("wait error");
            exit(1);
        }
        if(WIFEXITED(status))//为真，说明子进程正常终止
        {
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status))//为真，说明子进程是被信号终止
        {
            printf("child kill with signal %d\n",WTERMSIG(status));
        }
        printf("----------parent waitit finfish %d\n",wpid);
    }
}

