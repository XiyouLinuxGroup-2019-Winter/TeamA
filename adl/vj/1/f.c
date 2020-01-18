#include <stdio.h>
#include <ctype.h>
int main()
{
    int n;
    char ch;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {

        int sum = 0;
        while ((ch = getchar()) != '\n')
        {
            if (isdigit(ch))
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}