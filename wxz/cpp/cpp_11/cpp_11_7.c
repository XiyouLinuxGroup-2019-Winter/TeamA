#include <stdio.h>
char* string_in(char* dest,char* src);
int main()
{
	char s1[20]="hats";
	char s2[20]="at";
	char* ret=string_in(s1,s2);
	printf("%p\n",ret);
}
char* string_in(char*dest,char* src)
{
	int i;
	for(i=0;dest[i]!='\0';i++)
	{
		int temp=i;
		int j=0;
		while(dest[i++]=src[j++])
		{
			if(src[j]=='\0')
				return &dest[temp];
		}
		i=temp;
	}
	return NULL;
}
