/*************************************************************************
	> File Name: fork_exec.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 22时10分20秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char*argv[])
{
    int i;
    //for(i=0;i<5;i++)
        pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid==0)
    {
        
    // execlp("ls","ls","-l","-h",NULL);//argv[1],argv[2]
        //execlp("data","data",NULL);
        //execl("./a.out","./a.out",NULL);
        //execl("/bin/ls","ls","-l",NULL);
        //
        char *argv[]={"ls","-l","-h",NULL};
        execvp("ls",argv);
        perror("exec error");
        exit(1);
    }
    else if(pid>0)
    {
        sleep(1);
        printf("I am parent :%d\n",getpid());
    }
}

