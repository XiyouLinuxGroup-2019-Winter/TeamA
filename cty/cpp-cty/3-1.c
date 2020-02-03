#include<stdio.h>
#include<math.h>
int main(void)
{
        int a=2147483648;
        double b=1.8*(pow(10,38));
        float c=3.5*(pow(10,38));
        double d=-1.8*(pow(10,38));
        float e=-3.5*(pow(10,38));
        printf("%d\n %lf\n %f\n% lf\n %f\n",a,b,c,d,e);
        return 0;
}

