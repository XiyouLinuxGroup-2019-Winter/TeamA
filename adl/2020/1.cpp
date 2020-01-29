#include<stdio.h>
int i;
int main() 
{	i--;
	printf("%d\n",i);
	printf("%u\n",sizeof(i));
	printf("%u\n",i-sizeof(i));
	if(i>sizeof(i))
	printf("wow\n");
	
	
	return 0;
}
