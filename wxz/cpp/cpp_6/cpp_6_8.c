#include <stdio.h>
float value(float result)
{
	float a,b;
	while(scanf("%f %f",&a,&b)==2)
	result=(a-b)/(a*b);
	return result;
}
int main()
{
	printf("%f\n",value());
}
