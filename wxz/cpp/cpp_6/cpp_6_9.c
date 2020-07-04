#include <stdio.h>
int main()
{
	int up_limit,low_limit;
	int i,sum=0,n;
	printf("Enter lower and upper integer limits:");
	scanf("%d %d",&low_limit,&up_limit);
	while(low_limit<up_limit)
	{
		n=0;
		sum=0;
		for(i=low_limit;i<=up_limit;i++)
		{
			n=i*i;	
			sum+=n;
		}
		printf("The sums of the squares from %d to %d is %d\n",low_limit*low_limit,up_limit*up_limit,sum);
		printf("Enter next set of limits:");
		scanf("%d %d",&low_limit,&up_limit);
	}
}

