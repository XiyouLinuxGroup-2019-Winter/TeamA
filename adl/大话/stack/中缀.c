#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
//优先级：(  */   +-   )
// typedef char SElemType;
int priority[255] = {0};
int main()
{
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;

    Sqstack zstring;
    InitStack(&zstring);
    char s[100];
    fgets(s, 100, stdin);
    char *find = strchr(s, '\n');
    if (find)
    {
        *find = '\0';
    }
    int i = 0;
    while (s[i] != '#')
    {
        if (isdigit(s[i]))
            printf("%c ", s[i++]);
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            char w = zstring.top;
            if (zstring.top == -1)
            {
                Push(&zstring, s[i]);
                i++;
                continue;
            }
            if (zstring.data[zstring.top] == '(')
                Push(&zstring, s[i]);
            else if (priority[s[i]] > priority[w])
                Push(&zstring, s[i]);
            else if (priority[s[i]] <= priority[w]) //+
            {
                char e;
                while (priority[s[i]] <= priority[zstring.top])
                {
                    Pop(&zstring, &e);
                    printf("%c ", e);
                }
                Push(&zstring, s[i]);
            }
            i++;
        }
        else if (s[i] == '(')
        {
            Push(&zstring, s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            char e;
            while (zstring.data[zstring.top] != '(')
            {
                Pop(&zstring, &e);
                printf("%c ", e);
            }
            Pop(&zstring, &e);
            i++;
        }
    }
    if (zstring.top != -1)
    {
        char e;
        Pop(&zstring, &e);
        printf("%c ", e);
    }
    printf("#");
    return 0;
}