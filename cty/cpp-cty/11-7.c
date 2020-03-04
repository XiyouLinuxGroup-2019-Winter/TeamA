#include<stdio.h>
#define S_LENG 30
#define T_LENG 10
char* mystrncpy(char* s1, char* s2, int n);
char* s_gets(char* st, int n);
int main(void)
{
    char source[S_LENG];
    char target[T_LENG];
    char* tar;
 
    printf("Please enter some text.(empty line to quit)\n");
    while (s_gets(source, S_LENG) && *source != '\0')
    {
        tar = mystrncpy(target, source, T_LENG - 1);
        tar[T_LENG - 1] = '\0';
        printf("Target: \n");
        puts(tar);
        printf("\nEnter other text.(empty line to quit)\n");
    }
    printf("bye\n");
 
    return 0;
}
 
char* mystrncpy(char* s1, char* s2, int n)
{
    int count = 0;
    char* ret_val = s1;
 
    while (count < n)
    {
        *s1 = *s2;
        if (*s2 == '\0')
            break;
        s2++;
        s1++;
        count++;
    }
    return ret_val;
}
 
char* s_gets(char* st, int n)
{
    char* ret_val;
 
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
             st = '\0';
                     else
                                 while (getchar() != '\n')
                                                 continue;
                                                     }
                                                      
                                                          return ret_val;
            }
