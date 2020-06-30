#include<stdio.h>
int main()
{
    int N,M,n;
    int i;
    int sum;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d",&M);
        sum = 0;
        while (M--)
        {
            scanf("%d",&n);
            sum += n;
        }
        printf("%d\n", sum);
        if(i < N-1)
        {
            printf("\n");//最后这个地方没有空行
        }
  }
}
