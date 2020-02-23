#include <stdio.h>
int main()
{
	int a[4]={2,0,1,9};
	printf("%p,%p\n",a,&a);
	printf("%p,%p\n",a+1,&a+1);
}

