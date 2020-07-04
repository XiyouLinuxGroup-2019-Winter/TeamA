#include <stdio.h>
void print_ch(char ch,int i,int j);
int main()
{
	print_ch('#',3,4);
	printf("\n");
}
void print_ch(char ch,int i,int j)
{
	int k=0;
	int m=0;
	for(k=0;k<j;k++)
	{
		for(m=0;m<i;m++)
		printf("%c",ch);
		printf("\n");
	}
}	
