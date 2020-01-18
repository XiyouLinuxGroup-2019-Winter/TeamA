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
    int best[100]={0};
    int a, b;
    scanf("%d%d", &a, &b);
    getchar();
    char s[a][b];
    for (int i = 0; i < a; i++)
    {
            s_gets(s[i],b+1);   
    }
    for (int i = 0; i < b; i++) //b=5
    {
        int max = 0;
        for (int j = 0; j < a; j++)
            if (max < s[j][i]-'0')
                max = s[j][i]-'0';
        for (int j = 0; j < a; j++)
        {
            if (max == s[j][i]-'0')
            {
                best[j]=1;
            }
        }
    }
    int sum=0;
     for (int j = 0; j < a; j++)
        if(best[j]==1)
       sum++;
    printf("%d",sum);
        return 0;
}