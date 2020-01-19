/*************************************************************************
	> File Name: string_min.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 23时38分45秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    int n;
    char a[100][80];
    scanf("%d\n",&n);
    int i;
    for(i=0;i<n;i++)
    gets(a[i]);
    char*c;
    c=a[0];
    for(i=1;i<n;i++)
    {
        if(strcmp(c,a[i])>0)
            c=a[i];
    }
    printf("%s",c);
}
