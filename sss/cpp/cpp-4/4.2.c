#include <stdio.h>
#include <string.h>
int main()
{
	char a[20];
	printf("请输入名字");
	scanf("%s",a);
       int i;
       i=strlen(a);
	printf("%s\n",a);
	printf("\"%20s\"\n",a);
	printf("\"%-20s\"\n",a);
	printf("\"%s\"\n",a);
}

