#include <stdio.h>
int main ()
{
	int i,n,l=0;
	char a[1000];
	n=0;
	while((a[n]=getchar())!='\n')
		n++;
	int j;
	for(i=n-1;i>=0;i--)
	{
		

		if(a[i]==' '&&a[i+1]!=' ')
		{
			for(j=i+1;a[j]!=' '&&j<n;j++)
		        printf("%c",a[j]);
		        printf(" ");
		}
		//第一个单词加不上

		if(i==0&&l==0)
		{
			for(i=0;a[i]!=' ';i++)
	     			printf("%c",a[i]);
			l=1;
		}
        }
}


