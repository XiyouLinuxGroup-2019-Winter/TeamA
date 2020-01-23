#include <stdio.h>
#include <ctype.h>
void my_getchar(char* p,int n);
int main()
{
	int n;
	char a[100];
	scanf("%d",&n);
	getchar();
	my_getchar(a,n);
	fputs(a,stdout);
	putchar('\n');
}
void my_getchar(char* p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=getchar();
		if(isblank(p[i]))
			break;
	}
	p[i]='\0';
}
