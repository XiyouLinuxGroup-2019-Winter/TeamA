#include<stdio.h>
int main(void)
{
	double a=1.25;
	float b=a;
	if((float)a==b)
	{
		printf("Xiyou");
	}
	if(a!=b)
	{printf("linuxgroup\n");
	}
	printf("%.15f\n",a-b);
	printf("%.15f\n",((float)a-b));
	printf("%.15f\n",a);
	printf("%.15f\n",b);
	printf("%.15f\n",(float)a);

	return 0;
 } 
 
 
 
 
 //0100 0000 1001 0000 0000 0000 0000 0000
 //0100 0000 0001 0010 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 
