#include <stdio.h>
int main()
{
	int a=2147483647;
	float b=3.4e38;
	float c=3.4e38;
	printf("%d\n",a+1);
	printf("%e\n",b*100.0);
	printf("%e",b*(-100.0));
}

