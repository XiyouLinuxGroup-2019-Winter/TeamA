/*************************************************************************
	> File Name: fork_waitpid.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月29日 星期日 10时05分58秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    int i;
    pid_t pid,wpid,tmpid;
    for(i=0;i<5;i++)
    {
        pid=fork();
        if(pid==0)//循环期间，子进程不fork
        {
            if(i==2)
            {
                tmpid=pid;
                printf("-----pid= %d\n",tmpid);
            }
        break;
        }
    }
    if(i==5)//父进程，从表达式2跳出
    {
        sleep(5);
        //wait(NULL);//一次wait/waitpid函数调用，只能回收一个子进程
        //wpid=waitpid(-1,NULL;WNOHANG);//回收任意子进程，没有结束的子进程，父进程直接返回0
        //wpid=waitpid(pid,NULL,WNOHANG);//指定一个进程回收


        printf("I am parent,before waitpid pid=%d\n",tmpid);
        wpid=waitpid(tmpid,NULL,WNOHANG);//指定一个进程回收
        if(wpid==-1)
        {
            perror("waitpid error");
            exit(1);
        }
        printf("I am parent,wait a child fininsh :%d\n",wpid);
    }
    else
    {
        sleep(i);
        printf("I'm %dth child,pid=%d\n",i+1,getpid());
    }
    //printf("I'm %dth child\n",i+1);
}

