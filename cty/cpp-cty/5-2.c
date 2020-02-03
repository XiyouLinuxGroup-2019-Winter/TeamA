#include <stdio.h>

int main(void)
{
	int n;
	printf("请输入一个整数:");
	scanf("%d",&n);
	for(int i=0;i<10;++i)
	{
		printf("%d\t",++n);
	}
	return 0;
}
