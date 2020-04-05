#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
	char *ptr;
	int size=50;
	ptr=malloc(size);
	if(getcwd(ptr,size)==NULL)
	{
		perror("getcwd");
		exit(1);
	}
	printf("cwd=%s\n",ptr);
}


