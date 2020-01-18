#include<stdio.h>
#include<math.h>
int main()
{
    double r,v1,v2;
    double pai=atan(1.0)*4.0;
    while(scanf("%lf%lf%lf",&r,&v1,&v2)!=EOF)
    {
        if((v2-v1)/v1<pai)
        printf("Yes\n");
        else
        printf("No\n");
    }
   
    return 0;
}