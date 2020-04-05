#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
int main(int argc,char *argv[])
{

	int fd1=open(argv[1],O_RDWR);

	int fd2=open(argv[2],O_RDWR);

	int fdret=dup2(fd1,fd2);//返回新文件描述符，使得fd2也指向fd1.

	printf("fdret=%d\n",fdret);

	int ret=write(fd2,"1234567",7);//实际写入到了fd1指向的文件

	printf("ret=%d",ret);

	dup2(fd1,STDOUT_FILENO);//将屏幕输入重定向到fd1
	printf("----------------------------5678");

}

