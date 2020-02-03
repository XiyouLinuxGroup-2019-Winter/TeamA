#include<stdio.h>
int main(void)
{
int row, column;
char letter;
for (row = 1; row <= 6; row++)
{
for (column = 0, letter = 'F'; column < row; column++, letter--)
{
printf("%c", letter);
}
printf("\n");
}
return 0;
}
