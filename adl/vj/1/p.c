#include <string.h>
#include <stdio.h>

int ishuiwen(char s[])
{
    int len = strlen(s);
    for (int i = 0; i <= len - 1 - i; i++)
    {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}

int main()
{
    char s[51];
    scanf("%s", s);
    char *p = s;
    while (ishuiwen(p))
    {
        int len = strlen(p);
        p = p + len / 2;
        if (*(p + 1) == '\0')
        {
            printf("0");
            return 0;
        }
    }
    printf("%d", (int)strlen(p));
    return 0;
}