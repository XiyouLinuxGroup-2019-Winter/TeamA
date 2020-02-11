#include <stdio.h>
void asd (char *,char *,int);
int main()
{
	int n;
	char a[1000];
	n=0;
	while((a[n]=getchar())!='\n')
		n++;
	char b[100];
	asd(a,b,n);
	printf("%s",b);
}
void asd (char*a,char*b,int n)
{
	int i,h=0,k=0;
	b[0]=' ';
	for(i=0;i<n;i++)
	{
		if(a[i]==' '||a[i]=='	'||a[i]=='\n'&&b[0]==' ')
			continue;
                b[h++]=a[i];
                k=1;
		if(a[i]==' '||a[i]=='	'||a[i]=='\n'&&b[0]!=' ')
			break;
	}
}

