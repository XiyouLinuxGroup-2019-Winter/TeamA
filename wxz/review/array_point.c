/*************************************************************************
	> File Name: array_point.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月24日 星期一 11时42分28秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char a[10];
    int i;
    int cnt=0;
    for(i=0;i<10;i++)
    {
        a[i]=(char*)malloc(sizeof(char));
        scanf("%s",a[i]);
        cnt++;
        int n=strlen(a[i]);
        if(*(*(a+i)+(n-1))=='@')
            *(*(a+i)+(n-1))='\0';
        if(getchar()=='\n')
            break;
    }
    for(i=0;i<cnt;i++)
    {
        printf("%s\n",a[i]);
    }
}
