#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv,char **environ)
{
	int i;
	for(i=0;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n-------------------------\n");
	while(1);//一直运行，kill来杀死此进程
	return 10;
}

