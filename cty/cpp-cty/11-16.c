#include<stdio.h>
#include<ctype.h>
#include<string.h>
void print(void);
void to_up(void);
void to_low(void);
int main(int argc, char* argv[])
{
    if (argc > 2)
        printf("The parameter is incorrect.\n");
    else if (argc == 1 || !strcmp(argv[1], "-p"))
        print();
    else if (!strcmp(argv[1], "-u"))
        to_up();
    else if (!strcmp(argv[1], "-l"))
        to_low();
    putchar('\n');
 
    return 0;
}
 
void print(void)
{
    char ch;
 
    while((ch=getchar())!=EOF)
        putchar(ch);
}
 
void to_up(void)
{
    char ch;
 
    while ((ch = getchar()) != EOF)
    {
        ch = toupper(ch);
        putchar(ch);
    }
}
 
void to_low(void)
{
    char ch;
 
    while ((ch = getchar()) != EOF)
    {
        ch = tolower(ch);
        putchar(ch);
    }
}
