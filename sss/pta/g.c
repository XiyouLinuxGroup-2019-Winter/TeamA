#include <stdio.h>
#include <stdlib.h>
void MaxSum(int *p,int N)
{
            int ThisSum=0,MAX=0,i;
            for(i=0;i<N;i++)
	    {
                    ThisSum=ThisSum+p[i];
                     if(ThisSum>MAX)
                              MAX=ThisSum;
                     if(ThisSum<0)
                               ThisSum=0;
             }
             printf("%d",MAX);
}
int main()
{
             int N,*p,i;
             scanf("%d",&N);
             p=(int*)malloc(sizeof(int)*N);
             for(i=0;i<N;i++)
             scanf("%d",p+i);
             MaxSum(p,N);
}
