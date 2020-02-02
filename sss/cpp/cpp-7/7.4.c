#include <stdio.h>
#define stop '#'
int main()
{
	int count=0;
	char ch;
	while((ch=getchar())!=stop)
	{
		
		if(ch=='.')
		{
			ch='!';
			count++;
			putchar(ch);
		}

		else if(ch=='!')
		{
			
			count++;
			putchar('!');
			putchar('!');
		}
		else
			putchar(ch);
	}
	printf("\n");
	printf("%d",count);
}





