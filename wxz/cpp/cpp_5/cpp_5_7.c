#include <stdio.h>
void Cubic(float n) 
{
	float i;
	i=n*n*n;
	printf("%f",i);
}
int main()
{
	float n;
	scanf("%f",&n);
	Cubic(n);
	//printf("%f",n);
}
