#include<stdio.h>
#include<stdlib.h> 
int main(void)
{	char*p1;
	p1=(char*)malloc(5*sizeof(char));
	 
scanf("%s",p1);
printf("%p",p1);

	free(p1);
	return 0;
 } 
