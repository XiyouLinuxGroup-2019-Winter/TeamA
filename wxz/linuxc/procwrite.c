#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#define FIFO_NAME "myfifo"
#define BUF_SIZE 1024
int main()
{
    int fd;
    char buf[BUF_SIZE];

    umask(0);

    mkfifo(FIFO_NAME,S_IFIFO|0666);

    fd=open(FIFO_NAME,O_RDONLY);
    read(fd,buf,BUF_SIZE);
    
    write(fd,buf,strlen(buf)+1);
    close(0);
    exit(0);
}