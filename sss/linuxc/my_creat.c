#include <stdio.h>
//#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//#include <errno.h>
int main()
{
        int fd;
	fd=open("creat.txt",O_CREAT|O_RDWR,0600);
	if(fd==-1)
	{

		perror("open");
		exit(1);
	}
	else
		printf("succese\n");
	close(fd);
}


