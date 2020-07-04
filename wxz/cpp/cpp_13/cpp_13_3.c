#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	FILE* pf;
	char s[100];
	char ch;
	scanf("%s",s);
	if((pf=fopen(s,"a+"))==NULL)
	{
		printf("Can't open the %s\n",s);
	}
	while((ch=fgetc(pf))!=EOF)
	{
		if(islower(ch))
		{
			fseek(pf,-1,SEEK_CUR);
			putc(toupper(ch),pf);
			
		}
	}
	fclose(pf);
	pf=NULL;
}
