#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int fd;
	char buf[10];
	if((fd=open("rm.txt",O_RDWR|O_CREAT|O_TRUNC,0600))<0)
	{
		perror("open");
		exit(1);
	}
	if(write(fd,"teame",5)<0)
	{
		perror("write");
		exit(1);
	}
	if(lseek(fd,0,SEEK_SET)==-1)
	{
		perror("lseek");
		exit(1);
	}
	if(read(fd,buf,5)<0)
	{
		perror("read");
		exit(1);
	}
	if(unlink("rm.txt")<0)
	{

		perror("unlink");
		exit(1);
	}


}



