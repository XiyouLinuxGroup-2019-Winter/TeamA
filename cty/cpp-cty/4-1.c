#include <stdio.h>

int main(void)
{
	char a[20],b[20];
	printf("请输入您的名:");
	scanf("%s",&a);
	printf("请输入您的姓:");
	scanf("%s",&b);
	printf("'%s,%s'",a,b);
	return 0;
}
