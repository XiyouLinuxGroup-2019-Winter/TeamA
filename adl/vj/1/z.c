#include <stdio.h>
int main()
{
    int sum1[27] = {0};
    char s1[100];
    char s2[100];
    char s3[100];
    scanf("%s%s%s", s1, s2, s3);
    for (int i = 0; s1[i] != '\0'; i++)
    {
        sum1[s1[i] - 'A' + 1]++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        sum1[s2[i] - 'A' + 1]++;
    }
    for (int i = 0; s3[i] != '\0'; i++)
    {
        sum1[s3[i] - 'A' + 1]--;
    }
    for (int i = 0; i < 27; i++)
    {
        if (sum1[i] != 0)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}