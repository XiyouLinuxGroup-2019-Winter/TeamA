#include <stdio.h>
#include <string.h>
char* my_string(char* dest,char* src,int n);
int main()
{
	char a[100];
	char b[100]="asa sn eiw";
	char* c;
	c=my_string(a,b,strlen(b)-1);
	printf("%s\n",c);
}
char* my_string(char* dest,char* src,int n)
{
	char* ret=dest;
	for(int i=n;i>=0;i--)
	{
		if(*src!=' ')
		*dest++=*src++;
		else
		*src++;
	}
	*dest='\0';
	return ret;
}
