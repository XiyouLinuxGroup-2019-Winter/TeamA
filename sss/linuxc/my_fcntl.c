#include<stdio.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argt,char *argv[])
{
	int fd1,fd2;
	fd1=open("1.txt",O_CREAT|O_RDWR,0600);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}

	fd2=fcntl(fd1,F_DUPFD,9);
	printf("fd1=%d,fd2=%d\n",fd1,fd2);
	write(fd2,"bb",2);
	
}


