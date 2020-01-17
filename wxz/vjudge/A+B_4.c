/*************************************************************************
	> File Name: A+B_4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 11时33分28秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i,m;
        int sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            sum+=m;
        }
        printf("%d\n",sum);
        if(n==0)
        break;
    }
}
