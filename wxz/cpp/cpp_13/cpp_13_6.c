#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE* in,*out;
	int ch;
	char name[100];
	char file[100];
	int count=0;
	scanf("%s",name);
	if((in=fopen(name,"r"))==NULL)
	{
		fprintf(stderr,"I counldn't open the %s\n",name);
		exit(1);
	}
	strcpy(name,file);
	if((out=fopen(file,"w"))==NULL)
	{
		fprintf(stderr,"I counldn't open the %s\n",file);
		exit(2);
	}


	while((ch=getc(in))!=EOF)
	{
		if(count++%3==0)
			putc(ch,out);
	}
	fclose(in);
	fclose(out);
	in=NULL;
	out=NULL;
		
}
