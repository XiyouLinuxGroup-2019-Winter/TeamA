#include <stdio.h>

int main(void)
{
	float a,b[20];
	printf("请输入您的身高(英寸):");
	scanf("%f",&a);
	printf("请输入您的姓名:");
	scanf("%s",&b);
	printf("%s,you are %0.3f feet tall",a,b);
	return 0;
}
