#include<stdio.h>
#define F_LENG 30
#define S_LENG 30
char* s_gets(char* st, int n);
char* string_in(char* fst, char* sec);
int main(void)
{
    char first[F_LENG];
    char second[S_LENG];
    char* ret;
 
    printf("Please enter the first string.\n");
    if (s_gets(first, F_LENG))
    {
        printf("Your input: \"%s\"\n", first);
        printf("\nPlease enter the second string.(empty line to quit)\n");
        while (s_gets(second, S_LENG) && *second != '\0')
        {
            ret = string_in(first, second);
            if (ret)
            {
                printf("The rest:\n");
                puts(ret);
            }
            else
                printf("No such string,\n");
            printf("\nEnter other string.(empty line to quit)\n");
        }
    }
    printf("bye\n");
 
    return 0;
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
                                                           
                                                           char* string_in(char* fst, char* sec)
                                                           {
                                                               char* ret_val = NULL;
                                                                
                                                                    while (*fst != '\0')
                                                                       {
                                                                                if (*fst == *sec)
                                                                                            ret_val = fst;
                                                                                                    while (*fst == *sec)
                                                                                                            {
                                                                                                                        fst++;
                                                                                                                                    sec++;
                                                                                                                                                if (*sec == '\0')
                                                                                                                                                                return ret_val;
                                                                                                                                                                       }
            fst++;
                                                                                                                                                                         }                                                                                                                                                                             return NULL;
                       }
