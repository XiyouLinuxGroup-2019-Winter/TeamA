#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define LENGTH 10
int atoi(char* st);
int pow_i(int base, int n);
int main(void)
{
    char integer[LENGTH];
    int value;
 
    printf("Please enter an integer.\n");
    scanf("%s", integer, 10);
    value = atoi(integer);
    printf("\nInteger:\n%d\n", value);
 
    return 0;
}
 
int atoi(char* st)
{
    int value = 0;
    int len;
    int i = 0;
 
    len = strlen(st);
    while (*st != '\0')
    {
        if (!isdigit(*st))
        {
            value=0;
            break;
        }
        else
        {
            value += (*st - '0') * pow_i(10, len - 1 - i);
        }
        st++;
        i++;
    }
 
    return value;
}
 
int pow_i(int base, int n)
{
    int pow = 1;
 
    for (; n > 0; n--)
        pow *= base;
    return pow;
}
