#include<stdio.h>
int main(void)
{
int row;
int upper, lower;
int square, cube;
printf("Please enter the lower limit of integer: ");
scanf("%d", &lower);
printf("Please enter the upper limit of integer: ");
scanf("%d", &upper);
printf("\ninteger square cube\n");
for (row = lower; row <= upper; row++)
{
square = row * row;
cube = row * row * row;
printf("%7d %10d %10d\n", row, square, cube);
}
return 0;
}
 
