#include <stdio.h>
#include <math.h>
int main(void)
{
	int a;
	float b;
	printf("请输入水的夸脱数：");
	scanf("%d",&a);
	b=((a*950)/(3.0*1e-23));
	printf("水分子数量为:%f",b);
	return 0;
}
