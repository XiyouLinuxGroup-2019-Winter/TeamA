#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{

	int fd;
	off_t off;
	int PP;
	int ar[10]={0,1,2,3,4,5,6,7,8,9};
	fd=open("output.txt",O_CREAT|O_RDWR,0600);
	if(fd==-1)
	{
		perror("open");
		exit(1);

	}
	write(fd,ar,sizeof(ar));
	off=lseek(fd,5*sizeof(int),SEEK_SET);
	if(off==-1)
	{
		perror("lseek");
		close(fd);
		exit(1);
	}
	read(fd,&PP,sizeof(int));
	printf("%d",PP);
	close(fd);
}

			
