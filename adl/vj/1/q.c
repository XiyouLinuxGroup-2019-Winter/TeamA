#include <stdio.h>
#include <string.h>
char *s_gets(char *s, int n)
{
    char *f, *r;
    f = fgets(s, n, stdin);
    if (f)
    {
        r = strchr(s, '\n');
        if (r)
            *r = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return f;
}
int main()
{
    char s[101];
    while (s_gets(s, 101)!=NULL)
    {
        int len=strlen(s);
        for (int i = 0; i < len; i++)
        {
            if(i==0||s[i-1]==' ')
            {
                s[i]+='A'-'a';
            }

        }
        puts(s);
        
    }
        return 0;
}