#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
int main(int argc,char *argv[])
{

	if(argc<3)
	{

		printf("mv <filename> <filename>");
		exit(0);
	}

	if(rename(argv[1],argv[2])<0)
	{
		perror("rename");
		exit(0);
	}
}

