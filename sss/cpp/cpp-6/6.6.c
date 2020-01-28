#include <stdio.h>
int main()
{
	int min,max,i;
	printf("请输入下限");
	scanf("%d",&min);
	printf("请输入上限");
	scanf("%d",&max);
	for(i=min;i<max;i++)
	{
		printf("%d %d %d\n",i,i*i,i*i*i);
	}
}	
