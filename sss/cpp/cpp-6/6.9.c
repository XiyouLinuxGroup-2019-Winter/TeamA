#include <stdio.h>
double asd(float,float);
int main()
{
	float i,j;
	double as;
	printf("请输入两个数");
	scanf("%f %f",&i,&j);
	as=asd(i,j);
	printf("%lf",as);
}
double asd(float i,float j)
{
	double k,l;
	k=i-j;
	l=i*j;
	return k/l;
}


