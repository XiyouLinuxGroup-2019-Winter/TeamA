#include <stdio.h>
int main()
{
	float a,b;
	while(scanf("%f %f",&a,&b)==2)
	printf("%f\n",(a-b)/(a*b));
	
}
