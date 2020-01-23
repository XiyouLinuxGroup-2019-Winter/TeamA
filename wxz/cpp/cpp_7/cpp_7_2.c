#include <stdio.h>
#define stop '#'
int main()
{
	char ch;
	int count=0;
	while((ch=getchar())!=stop)
	{
		count++;
		printf("%c:%d ",ch,ch);
		if(count%8==0)
		printf("\n");
	}
}
