#include <stdio.h>
void pri(int a[][5],int n);
void dou(int a[][5],int n);
int main()
{
	int a[3][5];
	for(int i=0;i<3;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	pri(a,3);
	dou(a,3);
}
void pri (int a[][5],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			printf("%d",a[i][j]);
}
void dou(int a[][5],int n)
{
	for(int i=0;i<n;i++)
                  for(int j=0;j<5;j++)
		  {
			  a[i][j]=2*a[i][j];
                          printf("%d",a[i][j]);
		  }
}


