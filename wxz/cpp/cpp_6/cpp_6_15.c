#include <stdio.h>
int main()
{
	int count=0;
	float investda=100,investde=100;
	while(investda>=investde)
	{
		investda+=100*0.1;
		investde+=investde*0.05;
		count++;
	}
	printf("%d %f %f",count,investda,investde);
}
