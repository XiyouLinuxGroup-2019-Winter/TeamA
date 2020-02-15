#include <stdio.h>
int main()
{
	char x=-2,y=3;
	char t=(++x)|(y++);
	printf("x=%d,y=%d,t=%d\n",x,y,t);
	t=(++x)||(y++);
	printf("x=%d,y=%d,t=%d\n",x,y,t);
}

