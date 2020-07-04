#include <stdio.h>
#include <ctype.h>
char get_first(void)
{
	int ch;
	while(isspace(ch=getchar()));
	while(getchar()!='\n')
		continue;
		return ch;
}
int main()
{
	char ch;
	while((ch=get_first())!=EOF)
		putchar(ch);
}

