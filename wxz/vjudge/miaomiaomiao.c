/*************************************************************************
	> File Name: 淼淼淼.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 13时30分25秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char a[101];
    while(fgets(a,101,stdin))
    {
        int i;
        int len=strlen(a);
        for(i=0;i<len;i++)
        {
            if(i==0)
            a[i]=a[i]-32;
            if(a[i]==' ')
            a[i+1]=a[i+1]-32;
            printf("%c",a[i]);
        }
    }
}
