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
    int i,len;
    int sum=0;
    int n=0;
    while(scanf("%s",a)!=EOF)
    {
        int sum=0;
        len=strlen(a);
        if(a[0]=='0')
            continue;
        for(i=0;i<len;i++)
            sum+=a[i]-'0';
        if(sum<=9)
            return ;
        int n=0;
        while(sum>0)
        {
            n+=sum%10;
            sum=sum/10;
        }
        memset(a,'\0',sizeof(a));
        printf("%d\n",sum);
    }
}
