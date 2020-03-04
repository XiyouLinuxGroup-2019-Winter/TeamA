#include <stdio.h>
#include <math.h>
int prime(int n)
{
         int i=0;
         double m=sqrt(n);
         for(i=2;i<=m;i++)
          if(n%i==0)
               break;
         if(i>m)
                 return 1;
         else
		 return 0;

}
int main()
{
              int n,count=0,i=0;
              scanf("%d",&n);
              for(i=2;i<=n;i=i+1)
              if(prime(i)&&prime(i+2)&&!prime(i+1))
                      count++;
              printf("%d",count);
    return 0;
}
