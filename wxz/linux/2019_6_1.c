/*************************************************************************
	> File Name: 2019_6_1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月16日 星期日 15时15分21秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i=0,a=0,b=2,c=3,d=4;
    //i=a++ && ++b && d++;
    i = a++||++b||d++;
    printf("%d\n",i);
    printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c,d);
}