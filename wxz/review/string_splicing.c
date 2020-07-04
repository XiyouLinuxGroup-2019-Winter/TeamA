/*************************************************************************
	> File Name: string_splicing.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 23时28分34秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char a[100];
    scanf("%s",a);
    int i;
    int len=strlen(a);
    
    for(i=len-1;i>=0;i--)
    printf("%c",a[i]);
    for(i=0;a[i]!='\0';i++)
    printf("%c",a[i]);
   
}
