#include <stdio.h>
int main()
{
	float i,j;
	double k,l;
	while((scanf("%f %f",&i,&j))==2)
	{
		k=i-j;
		l=i*j;
		printf("%f\n",k/l);
	}
}

