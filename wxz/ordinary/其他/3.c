#include <stdio.h>
int main()
{
	int m,n;
	int sum;
	int i;
	while(scanf("%d",&n))
	{
		sum = 0;
		while(n--)
        	{
			scanf("%d",&m);
            		sum +=m;
        	}
        	printf("%d\n", sum);
   	 }
}	
