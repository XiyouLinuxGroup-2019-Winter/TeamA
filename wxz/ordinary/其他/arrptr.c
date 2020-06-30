#include <stdio.h>
int main()
{
	int a[2][5]={1,3,5,7,9,2,4,6,8,10};
	int (*p)[5],i;
	p=a;
	for(i=0;i<5;i++)
	printf("%d ",(*p)[i]);
	printf("\n");

	p++;//使p指向二维数组第二行
	for(i=0;i<5;i++)
	printf("%d ",(*p)[i]);
	printf("\n");
}
