/*************************************************************************
	> File Name: my_stat.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月27日 星期五 13时47分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
int main(int argc,char* argv[])
{
    struct stat sbuf;
    int ret=stat(argv[1],&sbuf);
    if(ret==-1)
    {
        perror("stat error:");
        exit(1);
    }
    printf("%ld\n",sbuf.st_size);

}
