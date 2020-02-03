#include<stdio.h>
#include<ctype.h>
#define LENGTH 20
int get_word(char* ar);
int main(void)
{
    char arr[LENGTH];
    char* p;
    int leng;
 
    printf("Please enter some text.\n");
    leng = get_word(arr);
    printf("\nWord:\n");
    for (p = arr; p < arr + leng; p++)
        putchar(*p);
    putchar('\n');
 
    return 0;
}
 
int get_word(char* ar)
{
    int length = 0;
    _Bool inword = 0;
 
    while (*ar=getchar())
    {
        if (isspace(*ar) && !inword)
            continue;
        else if (!isspace(*ar) && !inword)
            inword = 1;
        else if (isspace(*ar) && inword)
            break;
        length++;
        ar++;
    }
 
    return length;
}
