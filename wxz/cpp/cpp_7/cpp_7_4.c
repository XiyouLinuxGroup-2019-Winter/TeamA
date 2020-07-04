#include <stdio.h>
#define stop '#'
int main()
{
	char ch;
	int count1,count2;
	while((ch=getchar())!=stop)
	{	
		count1=0;
		count2=0;
		if(ch=='.')
		{
			putchar('!');
			count1++;
		}
		else if(ch=='!')
		{
			putchar('!');
			putchar('!');
			count2++;
		}
		else
		putchar(ch);
	}
	printf("%d %d\n",count1,count2);
}
