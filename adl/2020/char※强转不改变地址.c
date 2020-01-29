#include<stdio.h>
int main(void)
{
	int a=2;
	char b='x';
		printf("%p",&b); 
	printf("%p",&a); 
	printf("%d\n",*&a);
	printf("%p\n",(char*)&a);
	printf("%d\n",*(char*)&a);

	return 0;
}
