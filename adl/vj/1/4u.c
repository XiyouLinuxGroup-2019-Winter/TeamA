#include <stdio.h>
#include <string.h>
int main()
{
    char s[500009];
    int sum = 0;
    scanf("%s", s);
    int head=0, tail=-1;
    int len = strlen(s);
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '[' && (flag == 0))
        {
            head = i;
            flag = 1;
        }
        if (s[i] == ']')
            tail = i;
    }
    printf("%d\n%d\n",head,tail);
    int h = 0, t = 0;
    flag = 0;
    for (int i = head + 1; i < tail; i++)
    {

        if (s[i] == ':' && (flag == 0))
        {
            h = i;
            flag = 1;
        }
        else if (s[i] == ':' && (flag == 1||flag==2))
        {
            t = i;
            flag = 2;
        }
    }
    printf("%d\n%d\n", h, t);
    if (head >= tail || flag != 2)
    {
        printf("-1");
        return 0;
    }
    
    for (int i = h + 1; i < t; i++)
    {
        if (s[i] == '|')
            sum++;
    }
    printf("%d", sum + 4);
    return 0;
}