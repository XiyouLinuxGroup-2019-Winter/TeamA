1234567..........886
*****************************************************
	> File Name: dup.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月27日 星期五 20时23分13秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
    int fd=open(argv[1],O_RDONLY);
    int newfd=dup(fd);

    write(newfd,"1234567",7);
    printf("newfd:%d",newfd);
}
