#include <stdio.h>
int main()
{
	float inch,gallon;
	scanf("%f %f",&inch,&gallon);
	const float mile=1.609;
	const float gallonlitre=3.785;
	double kilometre=inch*mile;//公里
	double litre=gallon*gallonlitre;//升
	double literperkilometer=kilometre/litre;
	printf("%.1f\n",literperkilometer);
}
