#include<stdio.h>
int main(void)
{
int eight_int[8];
int i;
printf("Please enter eight integers.\n");
for (i = 0; i < 8; i++)
scanf("%d", &eight_int[i]);
printf("Inverted order.\n");
for (i = 7; i >= 0; i--)
printf("%d ", eight_int[i]);
printf("\n");
return 0;
}
