/*************************************************************************
	> File Name: fork_mmap.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月07日 星期二 02时15分01秒
 ************************************************************************/
#include <pthread.h>
#include<stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int var=100;
int main()
{
    int *p;
    pid_t pid;

    int fd;
    fd=open("temp",O_RDWR| O_CREAT|O_TRUNC,0644);
    if(fd<0)
    {
        perror("open  error");
        exit(1);
    }
    
    int ret=unlink("temp");
    if(ret==-1)
    {
        perror("unlink error");
        exit(1);
    }
    ftruncate(fd,4);

    p=(int *)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,fd,0);
    //p=(int *)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
   if(p==MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    close(fd);

    pid=fork();
    if(pid==0)
    {
        *p=7000;//写共享内存
        var=1000;
        printf("child, *p=%d,var=%d\n",*p,var);
    }
    else
    {
        sleep(1);
        printf("parent,*p=%d,var=%d\n",*p,var);//读共享内存
        wait(NULL);

        int ret=munmap(p,4);
        if(ret==-1)
        {
            perror("munmap error");
            exit(1);
        }
    }
}
