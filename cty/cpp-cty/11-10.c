#include<stdio.h>
#define LENGTH 20
char* s_gets(char* st, int n);
void d_blank(char* st);
int main(void)
{
    char string[LENGTH];
 
    printf("Please enter some text(empty line to quit).\n");
    while (s_gets(string,LENGTH) && *string != '\0')
    {
        printf("Original String: \n\"%s\"\n", string);
        d_blank(string);
        printf("Remove Space: \n\"%s\"\n", string);
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
                                                           
                                                           void d_blank(char* st)
                                                           {
                                                               char* p;
                                                                
                                                                    while (*st != '\0')
                                                                        {
                                                                                p = st;
                                                                                        if (*p == ' ')
                                                                                                {
                                                                                                            while (*p != '\0')
                                                                                                                        {
                                                                                                                                        *p = *(p + 1);
                                                                                                                                                        p++;
                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                                    st++;
                                                                                                                                                                                        }
             }
