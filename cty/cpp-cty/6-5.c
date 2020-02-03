#include<stdio.h>

int main(void)
{
int row, column;
int blank;
char letter;
char object;
printf("Please enter a capital letter: ");
scanf("%c", &object, 1);
for (row = 0; row < (object - 'A' + 1); row++)
{
for (blank = 0; blank < (object - 'A' - row); blank++)
printf(" ");
for (column = 0, letter = 'A'; column < (row + 1); column++, letter++)
printf("%c", letter);
for (letter -= 2; letter >= 'A'; letter--)
printf("%c", letter);
printf("\n");
}
return 0;
}
