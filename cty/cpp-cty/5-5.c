#include <stdio.h>

int main(void)
{
	int a,b,n;
	printf("请输入天数:");
	scanf("%d",&n);
	while(n>0)
	{
		a=0;
		b=0;
		while(a++<n)
		{
			b=b+a;
		}
	printf("总共赚取%d\n",b);
	printf("请再次输入天数:");
	scanf("%d",&n);
	} 
return 0;
}
