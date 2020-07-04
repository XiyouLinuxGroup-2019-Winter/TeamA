#include <stdio.h>
void critic(int* units);
int main()
{
	int units;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d",&units);
	while(units!=56)
		critic(&units);
	printf("You must have looked it up!\n");
}
void critic(int* units)
{
	printf("No luck,chummy.Try again.\n");
	scanf("%d",units);
}

