#include<stdio.h>
#include<ctype.h>
char get_first(void);
int main(void)
{
    printf("Please enter some text.\n");
    putchar(get_first());
    putchar('\n');
 
    return 0;
}
 
char get_first(void)
{
    char ch;
 
    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;
 
    return ch;
}
