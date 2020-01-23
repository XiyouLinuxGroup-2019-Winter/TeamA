#include <stdio.h>
#define space " "
void chline(char ch,int i,int j);
int main()
{
	chline('#',2,5);
}
void chline(char ch,int i,int j)
{
	int temp;
	temp=i;
	for(int j=1;j<i;j++)
		printf(" ");
	for(i=temp;i<=j;i++)
		putchar(ch);
	printf("\n");
}
