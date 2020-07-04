#include <stdio.h>
int main()
{
	int ch;
	int count=0;
	while(getchar()!=EOF)
		count++;
	printf("%d\n",count);
}

