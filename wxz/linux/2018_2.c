/*************************************************************************
	> File Name: 2018_2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 23时33分12秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[3][2]={2,0,1,8};
    char *str=(char*)malloc(sizeof(char)*20);
    strcpy(str,"\0101\\xb2");

    printf("%zu\n",sizeof(a));
    printf("%zu %d\n",sizeof(a[1][1]=0),a[1][1]);
    printf("%zu %zu\n",sizeof(str),strlen(str));

}
