/*************************************************************************
	> File Name: 淼淼.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 00时56分17秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char s[51];
    char a[51];
    scanf("%s",s);
    int i,j;
    int count=0;
    int len=strlen(s);
    for(i=len-1,j=0;i>=0;i--)
        a[j++]=s[i];
    a[j]='\0';
    if(strcmp(s,a)==0)
    {
        for(i=0;i<len/2;i++)
        {
            if(a[i]!=a[i+1])
            {
                count=len-1;
                break;
            }
            else
                count=0;
        }
    }
    else
        count=len;
    printf("%d",count);
}
