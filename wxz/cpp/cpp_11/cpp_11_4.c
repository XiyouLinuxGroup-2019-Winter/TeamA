#include <stdio.h>
#include <string.h>
void my_strchr(char*p,char ch);
int main()
{
	char a[100];
	fgets(a,100,stdin);
	my_strchr(a,'b');
}
void my_strchr(char*p,char ch)
{
	char* ret=p;
	if(*p=='\0')
		p=NULL;
	while(1)
		{
			if(*p==ch)
				printf("%p\n",p);
				else
				{
					if(*++p=='\0')
						p=NULL;
				}
		}	
}
