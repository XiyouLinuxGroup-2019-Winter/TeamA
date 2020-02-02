#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	printf("清输入数字");
	scanf("%d",&n);
	int l,k,i,j;
	k=0;
	if(n<=0)
		printf("输入数字错误");
	
	else
        {
		for(i=2;i<=n;i++)
		{
			l=0;
			for(j=2;j<=i/2;j++)
			{
				if(i%j==0)
				{
					l++;
                                        break;
				}
			}
			if(l==0)
			{
				printf(" %d",i);
                                k++;
			}
			if(k%10==0)
				printf("\n");
		}
	}
}

