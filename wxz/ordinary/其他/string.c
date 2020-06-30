#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,count=0;
	char a[1000];
	scanf("%d",&n);
	int b[n];
	for(i=0;i<n;i++)
	{
	scanf("%s",&a);
	for(j=0;j<strlen(a);j++)
	{
	if(a[j]>='0'&&a[j]<='9')
	{
	count++;
	}
	}
	b[i]=count;
	count=0;
	}
	for(i=0;i<n;i++)
	printf("%d\n",b[i]);
	return 0;	

}
