#include<stdio.h>
int main(void)
{
	int a[6]={0x6f796958,0x694c2075,0x2078756e,0x756f7247,0x30322070,0};

	printf("%d\n",printf("%s",(char*)a));
	printf("%c\n",*((char*)a)); 
	char b[6][4]={"Xiyo","u Li","nux ","Grou","p 20","\0"};
	
	printf("%p",b[0]);
	return 0;
 } 
