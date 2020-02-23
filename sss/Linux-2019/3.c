#include <stdio.h>
void f();
int main()
{
	int i;
	int k;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		f();
}
void f()

{
	static int a=0;
	int b=0;
	printf("%d %d ",++a,++b);
}

