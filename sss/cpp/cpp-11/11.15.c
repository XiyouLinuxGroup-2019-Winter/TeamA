#include <stdio.h>
int asd(char*,int);
int main()
{
	int n;
	scanf("%d",&n);
	char a[1000];
	n=0;
	while((a[n]=getchar())!='\n')
		n++;
	int h=asd(a,n);
	printf("%d",h);
}
int asd(char * a,int n)
{
	int i,h=1;
	for(i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			continue;
		else
			h=0;
	}
	return h;
}

