#include <stdio.h>
int main()
{
	double as[8],zx[8];
	int i,j,k;
	for(i=0;i<8;i++)
	{
		scanf("%lf",&as[i]);
		if(i==0)
		zx[i]=as[i];
		else
		zx[i]=zx[i-1]+as[i];
	}
	for(i=0;i<8;i++)
		printf(" %lf",as[i]);
	printf("\n");
	for(i=0;i<8;i++)
		printf(" %lf",zx[i]);
}


