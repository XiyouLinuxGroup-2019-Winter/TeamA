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
    int n;
    char s[101];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {

    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
        // printf("a\n");
        s_gets(s, 101);
       char * p = s;
        while ((*p)!='\0')
        {
            if (*p == 'a')
            {
                s1++;
            }
            else if (*p == 'e')
            {
                s2++;
            }
            else if (*p == 'i')
            {
                s3++;
            }
            else if (*p == 'o')
            {
                s4++;
            }
            else if (*p == 'u')
            {
                s5++;
            }
            p++;
        }
        printf("a:%d\n",s1);
        printf("e:%d\n",s2);
        printf("i:%d\n",s3);
        printf("o:%d\n",s4);
        printf("u:%d\n",s5);
        if(i!=n-1)
        printf("\n");
    }
    
    return 0;
}