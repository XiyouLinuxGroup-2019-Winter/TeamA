#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char temp[20];
    char** ch;
    char* p;
    int words;
    int i;
 
    printf("How many words do you wish to enter? ");
    while (!scanf_s("%d", &words))
    {
        while (getchar() != '\n')
            continue;
        printf("Please enter integer: ");
    }
    ch = (char **)malloc(words * sizeof(char*));
 
    printf("Enter %d words now:\n", words);
    for (i = 0; i < words; i++)
    {
        scanf_s("%s", temp, 20);
        p = (char*)malloc(sizeof(temp));
        strcpy_s(p, sizeof(temp), temp);
        ch[i] = p;
    }
 
    printf("Here are your words:\n");
    for (i = 0; i < words; i++)
    {
        puts(ch[i]);
        free(ch[i]);
    }
    free(ch);
 
    return 0;
}
