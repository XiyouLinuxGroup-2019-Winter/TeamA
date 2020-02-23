#include <stdio.h>
int asd(int);
int main()
{
	int n;
	scanf("%d",&n);
	int h=asd(n);
	printf("%d",h);
}
int asd(int n)
{
	if(n==1||n==2)
		return 1;
	else 
		return asd(n-1)+asd(n-2);
}

