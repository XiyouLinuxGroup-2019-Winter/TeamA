/*************************************************************************
	> File Name: fifo_W.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月31日 星期二 01时11分36秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
    int fd,i;
    char buf[4096];
    if(argc<2)
    {
        printf("enter like this:./a.out\n");
        return -1;
    }
    fd=open(argv[1],O_WRONLY);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    i=0;
    while(1)
    {
        sprintf(buf,"hello taciturn-wu %d\n",i++);
        write(fd,buf,strlen(buf));
        sleep(1);
    }
    close(fd);
}
