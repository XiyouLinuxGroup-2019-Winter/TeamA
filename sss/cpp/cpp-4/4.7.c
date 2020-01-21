#include <stdio.h>
#include <string.h>
int main()
{
	char a[20],b[20];
	printf("请输入名");
	scanf("%s",a);
	printf("清输入姓");
	scanf("%s",b);
	int i,j;
        i=strlen(a);
	j=strlen(b);
	printf("%s %s\n",a,b);
	printf("%*d%*d\n",i,i,j+1,j);
	printf("%s %s\n",a,b);
	printf("%-*d%-*d",i+1,i,j,j);
}
