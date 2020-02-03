#include <stdio.h>

int main(void)
{
	float a,b,c,d,e;
	printf("输入杯数:");
	scanf("%f",&a);
	b=a/2;
	c=a*8;
	d=a*16;
	e=a*48;
	printf("品脱:%f\n盎司:%f\n大汤勺:%f\n茶勺:%f\n",b,c,d,e);
	return 0;	
}
