#include <stdio.h>
int main()
{
	int ou=0,ou1=0,ji=0,ji1=0,n;
	int a[1000];
	n=0;
	while((scanf("%d",&a[n]))==1&&a[n]!=0)
		n++;
	int i;
	for(i=0;i<n;i++)
	{
	     if(a[i]%2==0)
	     {
		     ou++;
		     ou1+=a[i];
	     }
	     else
	     {
		     ji++;
		     ji1+=a[i];
	     }
	}
	printf("偶数%d个，平均数为%d\n",ou,ou1/ou);
	printf("奇数%d个，平均数为%d",ji,ji1/ji);
}




