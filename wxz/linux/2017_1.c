/*************************************************************************
	> File Name: 2017_1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 19时48分22秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int t=3;
    printf("%d\n",t);
    printf("%lu\n",sizeof(t--));
    printf("%d\n",t);
    printf("%lu\n",sizeof("ab c\nt\012\xa1*2"));
}
