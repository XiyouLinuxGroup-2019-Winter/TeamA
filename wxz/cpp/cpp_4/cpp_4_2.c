#include <stdio.h>
#include <string.h>
int main()
{
	char name[10];
	scanf("%s",name);
	printf("\"%s\"\n",name);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	int len=strlen(name);
	printf("%*s",len,name);

}
