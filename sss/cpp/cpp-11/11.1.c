#include <stdio.h>
void asd(char* p,int n);
int main()
{
	char a[100];
	int i,n;
	scanf("%d",&n);
	getchar();
	asd(a,n);
	for(i=0;i<n;i++)
		printf("%c",a[i]);
}
void my_getchar(char* p,int n)
{
	int i;
       for(i=0;i<n;i++)
	p[i]=getchar();
          
}

