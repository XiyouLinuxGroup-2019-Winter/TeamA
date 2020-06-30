#include <stdio.h>
/*int main()
{
	char a=-1;
	signed char b=-1;
	unsigned char c=-1;
	printf("a=%d,b=%d,c=%d",a,b,c);
}*/
int main()
{
	char a=-128;
	//100000000 00000000 00000000
	printf("%u\n",a);
}
