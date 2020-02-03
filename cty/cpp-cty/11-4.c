#include<stdio.h>
#include<ctype.h>
#define LENGTH 10
int get_word(char* ar, int n);
int main(void)
{
    char arr[LENGTH];
    char* p;
    int leng;
 
    printf("Please enter some text."
        "(Less than %d characters per word)\n",LENGTH);
    leng = get_word(arr, LENGTH);
    printf("\nWord:\n");
    for (p = arr; p < arr + leng; p++)
        putchar(*p);
    putchar('\n');
 
    return 0;
}
 
int get_word(char* ar, int n)
{
    char* p = ar;
    int length = 0;
    _Bool inword = 0;
 
    while (p < ar + n)
    {
        *p = getchar();
        if (isspace(*p) && !inword)
            continue;
        else if (!isspace(*p) && !inword)
            inword = 1;
        else if (isspace(*p) && inword)
            break;
        length++;
        p++;
    }
 
    return length;
}
