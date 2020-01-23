#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	char ch;
	while(--argc>0)
	{
		if((fp=fopen(*++argv,"r"))==NULL)
			{
				fprintf(stderr,"Can't open the %s\n",**++argv);
				//continue;
			}
	}
		while((ch=getc(fp))!=EOF)
			putchar(ch);
		printf("\n");
	fclose(fp);
	fp=NULL;
}
