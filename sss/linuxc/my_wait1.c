#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv,char **environ)
{
	int i;
	for(i=0;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n-------------------------\n");
	return 0;
}

