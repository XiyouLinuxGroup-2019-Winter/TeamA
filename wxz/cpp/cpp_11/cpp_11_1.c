#include <stdio.h>
void my_getchar(char* p,int n);
int main()
{
	char a[100];
	int n;
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
		p[i]=getchar();
	p[i]='\0';
}
