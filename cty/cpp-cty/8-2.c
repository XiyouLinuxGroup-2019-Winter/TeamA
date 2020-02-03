#include<stdio.h>
int main(void)
{
    char ch;
    int row=0;
 
    printf("Please enter some text.(end with EOF)\n");
    while ((ch = getchar()) != EOF)
    {
        if (ch != '\t' && ch != '\n' && ch < ' ')
            printf("^%c", ch + 64);
        else
            putchar(ch);
        printf("--%d  ", ch);
        if (row == '\n')
            row = 1;
        else
            row++;
        if (row == 10)
        {
            putchar('\n');
            row = 0;
        }
    }
    putchar('\n');
 
    return 0;
}
