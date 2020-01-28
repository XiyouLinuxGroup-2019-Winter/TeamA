#include <stdio.h>
int main()
{
	int asd[8];
	int i,j;
	for(i=0;i<8;i++)
		scanf("%d",&asd[i]);
	for(j=7;j>=0;j--)
		printf(" %d",asd[j]);
}

