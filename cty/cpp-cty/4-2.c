#include <stdio.h>
#include <string.h>
int  main(void)
{
	char n[20];
	printf("请输入您的名字:");
	scanf("%s",&n);
	printf("\"%s\"\n",n);
	printf("\"%20s\"\n",n);
	printf("\"%-20s\"\n",n);
	printf("\"%*s\"\n",strlen(n)+3,n);
	return 0;
}
