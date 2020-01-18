#include <stdio.h>
#include <string.h>
int main()
{
    char s[500009];
    int sum = 0;
    scanf("%s", s);
    int head, tail;
    int len = strlen(s);
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '[' && flag == 0)
        {
            head = i;
            flag = 1;
        }
        if (s[i] == ']')
            tail = i;
    }
    // printf("%d  %d\n",head,tail);
    flag = 0;
    int flag2 = 0;
    int temp = 0;
    for (int i = head + 1; i < tail; i++)
    {
        if (s[i] == ':' && flag == 0)
            flag = 1;
        else if (flag == 1 && s[i] == '|')
            temp++;
        else if (s[i] == ':' && flag == 1)
        {
            flag2 = 2;
            sum += temp;
            temp = 0;
        }
    }

    if (flag == 1 && flag2 == 2 && sum >= 0)
        sum += 4;
    else
        sum = -1;
    printf("%d", sum);
    return 0;
}