#include<stdio.h>
void chline(char ch, unsigned int i, unsigned int j);
int main(void)
{
    char ch;
    unsigned int row, column;
 
    printf("Please enter a character: ");
    ch = getchar();
    printf("Please enter the number of rows: ");
    scanf("%u", &row);
    printf("Please enter the number of columns: ");
    scanf("%u", &column);
    chline(ch, column, row);
 
    return 0;
}
 
void chline(char ch, unsigned int i, unsigned int j)
{
    unsigned int row, column;
 
    for (row = 0; row <j; row++)
    {
        for (column = 0; column < i; column++)
            putchar(ch);
        putchar('\n');
    }
}
