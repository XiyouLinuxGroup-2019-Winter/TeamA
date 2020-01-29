#include<stdio.h>
void as(int n);
int main(void)
{	char ch='1';
	char a[]="xi\0";
	char *b="xi\0";
	a[5]='\0';
	//b[5]='\0';
	printf("%s\n",a);
	printf("%s\n",b); 
	printf("%x\n",&ch);
 	as(3);
 } 
void as(int n)
{
	printf("%#p",&n);
}
