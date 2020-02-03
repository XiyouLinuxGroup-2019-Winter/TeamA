#include <stdio.h>

double cubes(double a);
int main(void)
{
	double num;
	printf("请输入一个数字:");
	scanf("%lf",&num);
	double cube_num=cubes(num);
	printf("%.2lf立方为%.2lf.",num,cube_num);
	return 0;
}

double cubes(double a)
{
	return a*a*a;
}
