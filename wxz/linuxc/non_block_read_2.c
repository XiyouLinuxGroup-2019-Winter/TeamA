/*************************************************************************
	> File Name: non_block_read_2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 02时35分02秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define MSG_TRY "try again\n"
#define MSG_TIMEOUT "timeout\n"
int main(void)
{
    char buf[10];
    int fd, n, i;
    fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
    if(fd<0) 
    {
        perror("open /dev/tty");
        exit(1);
    }
    for(i=0; i<5; i++) 
    {
         n = read(fd, buf, 10);
        if(n>=0)
            break;//说明读到了
        if(errno!=EAGAIN)
        {
            perror("read /dev/tty");
            exit(1);
        }
        sleep(1);
        write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
    }
    if(i==5)
        write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
    else
        write(STDOUT_FILENO, buf, n);
    close(fd);
}
