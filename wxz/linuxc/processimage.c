/*************************************************************************
	> File Name: processimage.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 03时04分55秒
 ************************************************************************/
//程序一：用来替换进程映像的程序
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char* argv[],char** environ)
{
    int i;
    printf("I am a process image!\n");
    printf("My pid=%d,parent= %d\n",getpid(),getppid());
    printf("uid =%d,gid=%d\n",getuid(),getgid());

    for(i=0;i<argc;i++)
        printf("argv[%d]:%s\n",i,argv[i]);

}

//exec函数实例，这里使用execve函数
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char* argv[],char** environ)
{
    pid_t pid;
    int stat_val;
    printf("Exec example!\n");
    pid=fork();
    switch(pid)
    {
        case -1:
            perror("Process Creation failed\n");
            exit(1);
        case 0:
            printf("Child process is running\n");
            printf("My pid= %d,parentpid=%d\n",getpid(),getppid());
            printf("uid=%d,gid=%d\n",getuid(),getgid());
            execve("processimage",argv,environ);
            printf("process never go to here!\n");
            exit(0);
        default:
            printf("Parent process is running\n");
            break;
    }
    wait(&stat_val);
    exit(0);
}

