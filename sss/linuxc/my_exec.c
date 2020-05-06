#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char **argv)
{

	pid_t ret=0;
	ret=fork();
	if(ret>0)
	{

	}

	else if(ret==0)
	{
		extern char **environ;
		execve("./new",argv,environ);
	}
}

