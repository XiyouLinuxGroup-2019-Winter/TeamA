#include <stdio.h>
#include<string.h>
int main()
{
	char str[512];
	int i;
	for(i=0;i<512;i++)
	{
		str[i]=-1-i;
	}
	printf("%lu\n",strlen(str));
}

