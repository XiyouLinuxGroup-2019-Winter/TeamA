#include <stdio.h>
void to_base_n(int n,int m)
{
	int r;
	r=n%m;
	if(n>=m)
		to_base_n(n/m,m);
	putchar('0'+r);
	return;
}
int main()
{
	int n;
	int m;
	while(scanf("%d %d",&n,&m)==2)
	{
		to_base_n(n,m);
		printf("\n");
	}
}
