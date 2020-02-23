#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *p=(char*)malloc(sizeof(char)*20);
	char *q;
	q=p;
	scanf("%s %s",p,q);
	printf("%s %s\n",p,q);
}

