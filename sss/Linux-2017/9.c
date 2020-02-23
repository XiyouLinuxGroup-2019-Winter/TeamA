#include <stdio.h>
int main()
{
	int a,b=2,c=5;
	for(a=1;a<4;a++)
	{
		switch(a)
		{
			b=99;
			case 2:
				printf("c is %d\n",c);
				break;
			default:
				printf("a is %d\n",a);
			case 1:
				printf("b is %d\n",b);
				break;
		}
	}
	return 0;
}   

