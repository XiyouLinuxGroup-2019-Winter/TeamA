#include <stdio.h>
int main()
{
    int a, b, c, s ;
    scanf("%d%d%d", &a, &b, &c);
    s=2*(a+c);
    if(s>a+b+c)
        s=a+b+c;
    if (s>2*(a+b))
        s=2*(a+b);
    if(s>2*(c+b))
        s=2*(c+b);
    printf("%d",s);
        return 0;
}