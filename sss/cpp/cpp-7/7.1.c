#include <stdio.h>
int main()
{
	char ch;
	int n;
	n=0;
	while((ch=getchar())!='#')
		n++;
	printf("%d",n);
}

