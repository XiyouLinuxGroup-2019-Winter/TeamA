#include <stdio.h>
   int main()
   {
          int i,m,j,l,n,sum;                                                            
          scanf("%d",&n);
          for(i=1;i<=n;i++)
           {       sum=0;
                   scanf("%d",&m);
                  for(j=1;j<=m;j++)
                  {
                          scanf("%d",&l);
                          sum+=l;
                  }
          if(i==1)
                  printf("%d",sum);
             else
                  printf("\n\n%d",sum);
          }
  }

