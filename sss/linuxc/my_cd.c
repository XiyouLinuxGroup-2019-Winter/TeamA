#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc,char *argv[])
{
	int size =100;
	char *buf;
	buf=malloc(size);
	if(argc<2)
	{
		printf("my_cd <target path>");
		exit(1);
	}
	if(chdir(argv[1])<0)
	{
		perror("chdir");
     		exit(1);
	}
	if(getcwd(buf,size)<0)
	{
		perror("getcwd");
		exit(1);
	}
        printf("%s\n",buf);
}

