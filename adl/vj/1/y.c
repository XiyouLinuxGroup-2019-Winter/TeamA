#include <stdio.h>
int main()
{
    int n, m; //9,3
    scanf("%d%d", &n, &m);
    getchar();
    char s[n];
    int cai[27]={0};
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &s[i]);
        cai[s[i] - 'A' + 1]++;
    }
    // for (int i = 1; i < m + 1; i++)
    // {

    //     printf("%d\n", cai[i]);
    // }

    int min = 100001;
    for (int i = 1; i < m + 1; i++)
    {
        if (min > cai[i])
            min = cai[i];
    }
    printf("%d", min * m);

    return 0;
}