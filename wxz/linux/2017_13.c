/*************************************************************************
	> File Name: 2017_10.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 20时58分58秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    char str[512];
    int i;
    for(i=0;i<512;++i)
    {
        str[i]=-1-i;
        printf("%d %c %d\n",i,str[i],str[i]);
    }
    
    printf("%lu\n",strlen(str));
}
