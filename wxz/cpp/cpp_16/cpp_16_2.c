/*************************************************************************
	> File Name: cpp_16_2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 00时50分33秒
 ************************************************************************/

#include<stdio.h>
#define har_aver(x,y) 1/(((1/x)+(1/y))/2)
int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    double c=har_aver(a,b);
    printf("%lf ",c);
}
