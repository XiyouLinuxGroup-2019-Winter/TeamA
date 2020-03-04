#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
        int prd,n,count=0,i,j,max;
        scanf("%d",&n);
        int flag=n;
        for(i=2;i<=sqrt(n);i++)
        {
                  prd=1;
         for(j=i;prd*j<=n;j++)
         {
             prd*=j;
            if(n%prd==0&&j-i+1>count)
            flag=i,count=j-i+1;
         }
        } 
         if(count==0)
          printf("1\n%d",flag);
         else
         {
                 printf("%d\n%d",count,flag);
                 for(i=flag+1;i<=flag+count-1;i++)
                 printf("*%d",i);
         }
}
