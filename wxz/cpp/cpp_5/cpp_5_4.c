#include <stdio.h>
#define IN 0.3937008
#define FT 0.0328084
int main()
{
	float height;
	double inch,feet;
	printf("Enter a height in centimeters:");
	scanf("%f",&height);
	while(height>0)
	{
		inch=IN*height;
		feet=FT*height;
		printf("%.1f cm=%.1f feet,%.1f inches\n",height,feet,inch);
		printf("Enter a height in centimeters (<=0 to quit):");
		scanf("%f",&height);
	}

}
