/*************************************************************************
	> File Name: 数字游戏.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 11时33分27秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char a[1001];
    while(scanf("%s",a) && strcmp(a,"0"))
    {
        int sum=0;
        int t;
       
        int i=0;
        int len=strlen(a);
        for(i=0;a[i]!='\0';i++)
            sum+=a[i]-'0';
           
        while(sum>=10)
        {
            t=sum;
            sum=0;
            while(t)
            {
                sum+=t%10;
                t=t/10;
            }
        }
        printf("%d\n",sum);
       
    }
          
}
