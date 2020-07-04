#include <stdio.h>
#include <ctype.h>
#define stop '#'
int main()
{
	char ch;
	int countspace=0;
	int countn=0;
	int countnum=0;
	while((ch=getchar())!=stop)
	{
		if(ch=='\n')
		countn++;
		if(isspace(ch))
		countspace++;
		if(isalnum(ch)||isprint(ch)||ispunct(ch))
		countnum++;
	}
	printf("%d %d %d",countspace,countn,countnum);
}
