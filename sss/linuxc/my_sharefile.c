#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	pid_t ret;
	int fd=0;

	ret=fork();

	if(ret>0)
	{

	       fd=open("./file.txt",O_RDWR|O_CREAT,0664);//都加上O_APPEND就不覆盖
	       write(fd,"hello\n",6);

	}

	else if(ret==0)
	{

		fd=open("./file.txt",O_RDWR|O_CREAT,0664);//此时会覆盖
		write(fd,"world\n",6);
	}
}



