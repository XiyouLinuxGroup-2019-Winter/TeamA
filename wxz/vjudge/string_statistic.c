/*************************************************************************
	> File Name: 字符串统计.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 12时08分08秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    char a[1000][1000];
    for(i=0;i<n;i++)
    scanf("%s",a[i]);
    
    int cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;a[i][j]!='\0';j++)
        {
            if(a[i][j]>='0'  && a[i][j]<='9')
                cnt++;
        }
        printf("%d\n",cnt);
        cnt=0;
    }
}
