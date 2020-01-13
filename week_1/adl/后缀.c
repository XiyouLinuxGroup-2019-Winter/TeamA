#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <ctype.h>
int main()
{
    Sqstack string;
    InitStack(&string);
    char s[100];
    char str[10];
    fgets(s,100,stdin);
    char*find=strchr(s,'\n');
    if(find)
    {
        *find= '\0';
    }
    int i = 0, j = -1, answer = 0, flag = 0;
    while (s[i] != '#')
    {
        if (isdigit(s[i]))
        {
            //Push(&string, s[i]);
            flag = 1;
            str[++j] = s[i];
            i++;
            continue;
        }
        if (flag == 1)
        {
            flag = 0;
            str[j+1] = '\0';
            j = -1;
            Push(&string, atoi(str));
        }
        if (ispunct(s[i]))
        {
            int e1, e2;
            Pop(&string, &e1);
            Pop(&string, &e2);
            if (s[i] == '+')
            {
                answer = e1 + e2;
                Push(&string, e1 + e2);
            }
            else if (s[i] == '-')
            {
                answer = e2 - e1;
                Push(&string, e2 - e1);
            }
            else if (s[i] == '*')
            {
                answer = e2 * e1;
                Push(&string, e2 * e1);
            }
            else if (s[i] =='/')
            {
                answer = e2 / e1;
                Push(&string, e2 / e1);
            }
            
        }
        i++;
    }
    printf("the answer is %d",answer);
}