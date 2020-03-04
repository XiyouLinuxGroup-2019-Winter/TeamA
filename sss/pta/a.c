#include <stdio.h>
#include <math.h>
int main()
{
     int n,i,j,count;
     double m;
     char ch;
     scanf("%d",&n);
     getchar();
     ch=getchar();
     double c=(n+1)/2.0;
     m=(double)sqrt(c);
     i=m;
     if(m!=i)
       m=i;
     count=n-2*m*m+1;
     for(i=1;i<=(2*m-1)/2;i++)
     {
             n=fabs(i-m);
             for(j=1;j<=i-1;j++)
             printf(" ");
             for(j=1;j<=2*n+1;j++)
             printf("%c",ch);
             printf("\n");
     }
     i=1;
     while(i<=((2*m-1)/2))
     printf(" "),i++;
     printf("%c\n",ch);
     for(i=(2*m-1)/2;i>=1;i--)
     {
             n=fabs(i-m);
             for(j=1;j<=i-1;j++)
             printf(" ");
             for(j=1;j<=2*n+1;j++)
             printf("%c",ch);
             printf("\n");
     }
    printf("%d",count);
    return 0;
}
