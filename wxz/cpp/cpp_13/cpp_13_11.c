#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	char s[100];
	if(argc<2)
	{
		fprintf(stderr,"参数错误\n");
		exit(1);
	}

	if((fp=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"Can't open the %s\n",argv[2]);\
		exit(2);
	}

	while(fgets(s,100,fp))
	{
		if(strstr(s,argv[1]))
			fputs(s,stdout);
	}
	fclose(fp);
	fp=NULL;

}
