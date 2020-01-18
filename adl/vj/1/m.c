#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    char c[100];
    scanf("%s", s + 1);
    s[0] = '0';
    if(strcmp(s,"00")==0)
    {
        printf("0");
        return 0;
    }
    int len = strlen(s) - 1;
    
    int k = len ;
    int j = 1;
    while (k >= 0)
    {
        if (s[k] - '0' + j == 10)
        {
            s[k] = '0';
            j = 1;
        }
        else
        {
            s[k]++;
            j = 0;
            break;
        }
        k--;
    }
    
    if ((s[len] - '0') % 2 == 1)//~~~~1
    {
        if (s[0] == '0')
            printf("%s", s + 1);
        else
            printf("%s", s);
    }
    else//~~~~~0
    {
        int u=0,add=0,he=0;
        while (u<=len)
        {
            he=s[u]-'0'+add;
            if(he/2==0)
            {
                add=(s[u]-'0')*10;
                s[u]='0';
            }
            else
            {
                add=(he%2)*10;
                s[u]=he/2+'0';
            }
            u++;    
        }
        int i=0;
        while (s[i]=='0')
        {
            i++;
        }
        printf("%s",s+i);
        
        
    }
}