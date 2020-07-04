#include <stdio.h>
#include <string.h>
void return_max(int a[])
{
	int max=a[0];
	for(int i=0;i<5;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	printf("%d\n",max);
}
int main()
{
	int a[5]={1,2,3,4,5};
	int b;
	return_max(a);
}
