/*************************************************************************
	> File Name: u.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月21日 星期二 12时45分14秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    scanf("%s",s);
    int i;
    int len=strlen(s);
    
    int head=0;
    int tail=0;
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='[')
        {
            head=i;
            flag=1;
        }
        if(s[i]==']')
            tail=i;
    }
    
    int flag2=0;
    int cnt=0;
    int sum=0;
    flag=0;
    for(i=head+1;i<tail;i++)
    {
        if(s[i]==':' && flag==0)
            flag=1;
        else if(s[i]=='|' && flag==1)
            cnt++;
        else if(s[i]==':' && flag==1)
        {
            flag2=1;
            sum+=cnt;
        }
    }
    if(flag==1 && flag2==1)
    {
        sum+=4;
        printf("%d",sum);
    }
    else
    {
        sum=-1;
        printf("%d",sum);
    }
}
