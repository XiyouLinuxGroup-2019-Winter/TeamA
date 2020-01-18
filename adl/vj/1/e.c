#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m, s = 0,t;
        scanf("%d", &m);
        for (int k = 0; k < m; k++)
        {
            scanf("%d",&t);
            s += t;
        }
        if(i==0)
        printf("%d", s);
        else
        printf("\n\n%d",s);
        
    }
    printf("\n");
}
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m, s = 0,t;
        scanf("%d", &m);
        for (int k = 0; k < m; k++)
        {
            scanf("%d",&t);
            s += t;
        }
        printf("%d\n\n", s);
        
    }
}