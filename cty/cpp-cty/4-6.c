#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[20],b[20];
	printf("请输入您的名:");
	scanf("%s",&a);
	printf("请输入您的姓:");
	scanf("%s",&b);
	printf("%s %s\n%*d %*d\n",a,b,strlen(a),strlen(a),strlen(b),strlen(b));
	printf("%s %s\n%-*d %-*d\n",a,b,strlen(a),strlen(a),strlen(b),strlen(b));
	return 0;	
}
