#include <stdio.h>
int main()
{
	int i,j,k;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand:");
	scanf("%d",&i);
	printf("Enter the first operand:");
	while((scanf("%d",&j)==1)&&j>0)
	{
	        printf("%d对%d取模 is %d\n",j,i,j%i);
                printf("Enter next number for first operand:");
	}
        printf("Done");
}

