/*************************************************************************
	> File Name: mmp_test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月06日 星期五 23时56分47秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
int main(void)
{

    printf("hello world\n");
    /*int *p;
    int fd = open("hello", O_RDWR);
    if (fd < 0) 
    {
        perror("open hello");
        exit(1);
    }
    p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) 
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    p[0] = 0x30313233;
    munmap(p, 6);*/
}
