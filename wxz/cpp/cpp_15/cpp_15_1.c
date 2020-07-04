/*************************************************************************
	> File Name: cpp_15_1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 01时10分59秒
 ************************************************************************/

#include<stdio.h>
int transite(char* pf);
int main()
{
    char* pbin="01001001";
    int i=transite(pbin);
    printf("%d\n",i);
}
int transite(char* pf)
{
    int i=0;
    int n=0;
    for(i=0;pf[i];i++)
    {
        n<<=1;
        n |=(pf[i]-'0');
    }
    return n;
}
