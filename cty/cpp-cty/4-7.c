#include <stdio.h>
#include <float.h>
int main(void)
{
	float a;
	double b;
	a=1.0/3.0;
	b=1.0/3.0;
	printf("%d %d\n",FLT_DIG,DBL_DIG);
	printf("%.4f %.4lf\n",a,b);
	printf("%.12f %.12lf\n",a,b);
	printf("%.16f %.16lf\n",a,b);
	system("pause");
	return 0;
}
