#include <stdio.h>
int main()
{
	int i;
	int min,max,sum=0;
	printf("Enter lower and upper integer limits:");
	scanf("%d%d",&min,&max);
        while(min-max<0)
	{  sum=0;
	   for(i=min;i<=max;i++)
           sum+=i*i;
	   printf("The sums of the squares from %d to %d is %d\n",min*min,max*max,sum);
	   printf("Enter next set of limits:");
	   scanf("%d%d",&min,&max);
	}
	printf("Done");
}

