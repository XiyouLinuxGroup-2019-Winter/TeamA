#include <stdio.h>
#include <stdlib.h>
int count(int ch,FILE* f);
int main(int argc,char* argv[])
{
	FILE* fp;
	if(argc<2)
	{
		fprintf(stderr,"参数错误\n");
		exit(1);
	}
	else if(argc==2)
	{
		printf("%s\n",argv[1]);
		printf("文件名:%s,计数值:%d\n",argv[1],count(*argv[1],stdin));
	}
	else
	{
		for(int i=2;i<argc;i++)
			if((fp=fopen(argv[i],"r"))==NULL)
			{
				fprintf(stderr,"Can't open the %s\n",argv[i]);
				exit(2);
			}
		for(int i=2;i<argc;i++)
			printf("文件名:%s，计数值:%d",argv[i],count(*argv[i],fp));
			fclose(fp);
			fp=NULL;
	}
}
int count(int ch,FILE* f)
{
	int ret=0;
	char ef;
	while((ef=getc(f))!=EOF)
	{
		if(ch==ef)
			ret++;
	}
	return ret;
}
