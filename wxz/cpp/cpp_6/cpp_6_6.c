#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];
	char b[1000];
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	for(i=len;i>=0;i--)
	printf("%c",a[i]);
	printf("\n");
}
