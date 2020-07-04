/*************************************************************************
	> File Name: fork_waitpid_while.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月29日 星期日 10时35分17秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc,char* argv[])
{
    int i;
    pid_t pid,wpid;
    for(i=0;i<5;i++)
    {
        pid=fork();
        if(fork()==0)
            break;
    }
    if(i==5)
    {
        
        /*while((wpid=waitpid(-1,NULL,0)))
        {
            printf("wat child %d\n",wpid);
        }*/
        while((wpid=waitpid(-1,NULL,WNOHANG))!=-1)
        {
            if(wpid>0)
            {
                printf("wait child %d\n",wpid);
            }
            else if(wpid==0)
            {
                sleep(1);
                continue;
            }
        }
       
    }


    else
    {
        sleep(i);
        printf("I'm %dth child,pid=%d\n",i+1,getpid());
    }

}

