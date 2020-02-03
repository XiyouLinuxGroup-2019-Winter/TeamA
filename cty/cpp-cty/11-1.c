#include<stdio.h>
#define LENGTH 10
void get_char(char* ar, char *end);
int main(void)
{
    char arr[LENGTH];
    char* p;
 
    printf("Please enter %d characters.\n", LENGTH);
    get_char(arr, arr + LENGTH);
    printf("\ncharacter array:\n");
    for (p = arr; p < arr + LENGTH; p++)
        putchar(*p);
    putchar('\n');
 
    return 0;
}

void get_char(char* ar, char *end)
{
    for (; ar < end; ar++)
          * ar = getchar();
}
