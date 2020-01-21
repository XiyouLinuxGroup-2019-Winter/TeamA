#include <stdio.h>
#include <float.h>
int main()
{
	float i=1.0/3.0;
	double j=1.0/3.0;
	printf("%.6f %.12f %.16f\n",i,i,i);
	printf("%.6f %.12f %.16f\n",j,j,j);
	printf("%d %d",FLT_DIG,DBL_DIG);
}


