#include<stdio.h>
int main()
{
	int n;
	char a[100];
	int i;
	scanf("%c",&a[0]);
	for(n=1;a[n-1]!='\n';n++)
		scanf("%c",&a[n]);
        for(i=0;i<n/2;i++)
	{
		int t;
		t=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
	}

		
	printf("%s",a);
}

