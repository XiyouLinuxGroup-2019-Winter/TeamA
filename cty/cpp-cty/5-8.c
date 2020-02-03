#include <stdio.h>

int main(void)
{
	int one, two, moduli;
	printf("This program computers moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	scanf("%d", &two);
	printf("Now enter the first operand: ");
	scanf("%d", &one);

while (one > 0)
{
	moduli = one % two;
	printf("%d %% %d is %d.\n", one, two, moduli);
	printf("Enter next number for first operand (<= 0 to quit): ");
	scanf("%d", &one);
}
printf("Done");
return 0;	
}
