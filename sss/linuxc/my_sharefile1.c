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
        open("./file1.txt",O_RDWR|O_CREAT,0664);
	ret=fork();

	if(ret>0)
	{

	       
	       write(fd,"hello\n",6);

	}

	else if(ret==0)
	{

	
		write(fd,"world\n",6);
	}
}



