#include <stdio.h>
int isPerfect(int n)
{
    int i,m=0;
    for (i=1; i<=n/2; i++) {
        if (n%i==0)
            m+=i;
    }
    if (m==n)
        return 1;
    return 0;
}
int main() {
    int N,a,b,c;
    scanf("%d",&N);
    while (N--) {
        scanf("%d %d",&a,&b);
        int num=0;
        if (a>b) {
            c=a;
            a=b;
            b=c;
        }
        for (int i=a; i<=b; i++) {
            if (isPerfect(i)==1)
                num++;
        }
        printf("%d\n",num);
    }
    return 0;
}
