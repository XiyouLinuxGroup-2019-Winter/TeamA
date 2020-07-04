#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ch;
	FILE* fp;
	char s[100];
	long count=0;

	scanf("%s",s);
	if((fp=fopen(s,"r"))==NULL)
	{
		printf("Can't open %s\n",s);
		exit(1);
	}
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters\n",s,count);
}
