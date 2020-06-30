#include <stdio.h>
int main()
{
	int sum[1000];
	int n,m,i,j,a;
	int k=0;
	scanf("%d",&n);
 	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&a);
			sum[k]+=a;
		}
		//sum[k]+=a;
		//k++;
		k++;
	}
	for(i=0;i<k;i++)
	printf("%d\n",sum[i]);
}
