#include <stdio.h>
int main()
{
    int n, i;
    int s[100] = {0, 1};
    int flag=1;
    while (scanf("%d", &n) != EOF)
    {
        
        if (flag == 1)
        {
            flag=0;
        }
        else
        {
            printf("\n");
        }
        int temp[100] = {0, 1};
        for (i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                s[j] = temp[j - 1] + temp[j];
            }
            for (int j = 0; j <= i; j++)
            {
                temp[j] = s[j];
            }

            for (int j = 1; j <= i; j++)
            {
                printf("%d ", s[j]);
            }
            printf("\n");
        }
    }
    return 0;
}