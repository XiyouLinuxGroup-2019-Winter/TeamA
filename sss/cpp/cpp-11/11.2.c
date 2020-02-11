#include <stdio.h>
#include <string.h>
void asd(char *,int n);
int main()
{
	int n;
	char a[1000];
	scanf ("%d",&n);
	getchar();
	asd(a,n);
	n=strlen(a);
	for(int i=0;i<n;i++)
		printf("%c",a[i]);
}
void asd(char *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=getchar();
		if(a[i]==' '||a[i]=='	'||a[i]=='\n')
			break;
	}
	a[i]='\0';
}


