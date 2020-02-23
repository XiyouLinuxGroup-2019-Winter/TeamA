#include <stdio.h>
int main()
{
	int a,b,c;
	a=1;b=2;c=3;
	/*c=a;
	a=b;
	b=c;*/
	a=a-b;
	b=b+a;
	a=b-a;

	printf("%d %d %d",a,b,c);
}

