#include<stdio.h>
#include<string.h>
#define LENGTH 20
char* s_gets(char* st, int n);
void re_order(char* st);
int main(void)
{
    char string[LENGTH];
 
    printf("Please enter some text(empty line to quit).\n");
    while (s_gets(string, LENGTH) && *string != '\0')
    {
        printf("Your input: \"%s\"\n", string);
        re_order(string);
        printf("Reverse Order:\n");
        puts(string);
        printf("\nEnter other string(empty line to quit).\n");
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
                                                           
                                                           void re_order(char* st)
                                                           {
                                                               int i;
                                                                   int n;
                                                                       int temp;
                                                                        
                                                                            n = strlen(st);
                                                                                for (i = 0; i < n / 2; i++)
                                                                                    {
                                                                                            temp = st[i];
                                                                                                    st[i] = st[n - i - 1];
                                                                                                            st[n - i - 1] = temp;
                                                                                                              }
            }
