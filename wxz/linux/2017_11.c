/*************************************************************************
	> File Name: 2017_8.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 20时55分26秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int num[5]={2,4,6,8,10};
    int* ptr=(int*)(&num+1);
    printf("%d %d\n",*(num+1),*(ptr-1));
}
