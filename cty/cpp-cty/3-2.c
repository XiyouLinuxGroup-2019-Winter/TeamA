#include <stdio.h>
int main(void)
{
	int a;
	char x;
	printf("请输入一个ASCII码值：");
	scanf("%d",&a);
	x=(char)a;
	printf("%c",x);
	return 0;
}
