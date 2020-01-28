#include <stdio.h>
int main()
{
    int i,j,m;
   double sum;
   scanf("%d",&m);
   while(m)
   {       sum=1.0;
	   for(i=2;i<=m;i++)
	      sum+=1.0/(i*1.0);
	   printf("%lf\n",sum);
	   scanf("%d",&m);
   }
}

     
