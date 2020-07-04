/*************************************************************************
	> File Name: 2017_17.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 21时41分16秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char a;
    short b;
    int c;
};

int main()
{
    struct node s;
    printf("%d\n",sizeof(s));
    memset(&s,0,sizeof(s));
    s.a=3;
    s.b=5;
    s.c=7;
    struct node* pt=&s;
    printf("%d\n",*(int*)pt);
    printf("%lld\n",*(long long *)pt);
}
