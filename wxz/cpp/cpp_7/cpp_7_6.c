#include <stdio.h>
#define stop '#'
int main()
{
	char ch;
	char ch_e;
	int count=0;
	while((ch=getchar())!=stop)
	{
		if(ch=='e')
		ch_e=ch;
		if(ch=='i'&&ch_e=='e')
		count++;
	}
	printf("%d\n",count);
}
