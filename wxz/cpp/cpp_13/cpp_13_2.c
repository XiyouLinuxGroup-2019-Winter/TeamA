#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
	int ch;
	FILE *in,*out;
	int count=0;
	char name[100];
	size_t bytes;
	if(argc<2)
	{
		fprintf(stderr,"错误的参数:%s\n",argv[0]);
		exit(1);
	}
	if((in=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr,"I counld't open the \"%s\"\n",argv[1]);
		exit(2);
	}
	if((out=fopen(argv[2],"wb"))==NULL)
	{
		fprintf(stderr,"I counld't open the %s\n",argv[2]);
		exit(3);
	}
	strcpy(name,argv[1]);
	while((ch=getc(in))!=EOF)
	{
			putc(ch,out);
	}
	//while((bytes=fread(&ch,sizeof(ch),1,in)) && !feof(in))
		//fwrite(&ch,sizeof(ch),1,out);
	//说实话这段我不太懂

	if(fclose(in) || fclose(out))
	{
		fprintf(stderr,"退出失败\n");
		exit(4);
	}

}
