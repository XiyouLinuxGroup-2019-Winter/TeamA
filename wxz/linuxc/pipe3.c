/*************************************************************************
	> File Name: pipe2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月29日 星期日 11时38分39秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc,char* argv[])
{
    int ret;
    pid_t pid;
    int fd[2];
    char *str="hello pipe\n";
    char buf[1024];

    ret=pipe(fd);
    if(ret==-1)
        perror("pipe error");

    pid=fork();
    if(pid>0)
    {
        close(fd[0]);//关闭读端
        sleep(3);//父进程上来就睡觉，子进程上来就读数据，造成阻塞
        //write(fd[1],str,strlen(str));
        close(fd[1]);
    }
    else if(pid==0)
    {
        close(fd[1]);//关闭写端
        ret=read(fd[0],buf,sizeof(buf));
        printf("child read ret=%d\n",ret);
        write(STDOUT_FILENO,buf,ret);
        close(fd[0]);
    }
}
