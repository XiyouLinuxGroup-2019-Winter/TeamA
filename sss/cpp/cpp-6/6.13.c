#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,k;
	int asd[8];
	for(i=0;i<8;i++)
		asd[i]=pow(2,i+1);
	do
	{
		printf("%d",asd[i]);
	}
	while(i--);
}


