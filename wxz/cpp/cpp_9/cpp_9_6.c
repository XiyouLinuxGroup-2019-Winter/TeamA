#include <stdio.h>
#include <ctype.h>
int charposition(char ch)
{
		int i;
		if(isalpha(ch))
		{
			if(ch=tolower(ch))
			i=ch-'a'+1;
		}
		else
		return -1;
}
int main()
{
	char ch;
	while((ch=getchar())!=EOF)
		{
			int i;
			i=charposition(ch);
			//if(i==-1)
		//	else
			printf("%d\n",i);
		}
	
}
