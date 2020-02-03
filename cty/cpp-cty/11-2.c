#include<stdio.h>
#include<ctype.h>
#define LENGTH 10
int get_char(char* ar, char* end);
int main(void)
{
    char arr[LENGTH];
    char* p;
    int leng;
 
    printf("Please enter some text.\n");
    leng = get_char(arr, arr + LENGTH);
    printf("\ncharacter array:\n");
    for (p = arr; p < arr + leng; p++)
        putchar(*p);
    putchar('\n');
 
    return 0;
}
 
int get_char(char* ar, char* end)
{
    int length = 0;
 
    for (; ar < end; ar++, length++)
    {
        *ar = getchar();
        if (isspace(*ar))
            break;
    }
 
    return length;
}
