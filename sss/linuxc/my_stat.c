#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
int main(int argc,char *argv[])
{
        struct stat buf;
	if(argc!=2)
	{
		printf("usage:my_stat <filename>\n");
		exit(0);
	}
        if(stat(argv[1],&buf)==-1)
	{

		perror("stat:");
		exit(1);
	}
        printf("device : %d\n",buf.st_dev);
	printf("inode : %d\n",buf.st_ino);
	printf("mode : %o\n",buf.st_mode);
}

