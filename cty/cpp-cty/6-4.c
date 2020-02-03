#include<stdio.h>
int main(void)
{
int row, column;
char letter;
for (row = 1, letter = 'A'; row <= 6; row++)
{
for (column = 0; column < row; column++, letter++)
{
printf("%c", letter);
}
printf("\n");
}
return 0;
}
 
