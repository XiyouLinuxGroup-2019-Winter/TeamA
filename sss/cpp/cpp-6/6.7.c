#include <stdio.h>
int main()
{
	int n;
	char a[30];
	n=0;
	while((a[n]=getchar())!='\n')
		n++;
	for( ;n>=0;n--)
		printf("%c",a[n]);
}

