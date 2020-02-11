#include <stdio.h>
void asd(char *,int);
int main()
{
	int n;
	n=0;
	char a[100];
	while((a[n]=getchar())!='\n')
		n++;
	asd(a,n);
	printf("%s",a);
}
void asd(char *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(a[i]==' ')
		{
			for(j=i;j<n;j++)
				a[j]=a[j+1];
			i--;
			n--;
		}


	}
}


