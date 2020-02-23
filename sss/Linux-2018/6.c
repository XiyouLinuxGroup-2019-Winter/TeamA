#include <stdio.h>
int main()
{
	int a[5];
	printf("%p\n",a);
	printf("%p\n",a+1);
	printf("%p\n",&a);
	printf("%p\n",&a+1);
	return 0;
}

