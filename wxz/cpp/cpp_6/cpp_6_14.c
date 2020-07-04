#include <stdio.h>
#include <string.h>
int main()
{
	char a[256];
	int i=0,j=0;
	scanf("%c",&a[i]);
	while(a[i]!='\n')
	{
		++i;
		scanf("%c",&a[i]);
	}
	for(j=i;j>=0;j--)
	printf("%c",a[j]);
	printf("\n");
	/*char a[256];
	int len,i,j;
	scanf("%s",&a);
	len=strlen(a);
	for(i=len-1;i>=0;i--)
	printf("%c",a[i]);*/
}
