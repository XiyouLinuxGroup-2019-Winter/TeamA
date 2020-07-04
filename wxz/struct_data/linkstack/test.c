/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月05日 星期二 00时56分42秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "linkstack.h"

int main()
{
    int a[10],i=0;
    LinkStack* stack=LinkStack_Create();
    if(stack==NULL)
    {
        return -1;
    }
    for(i=0;i<5;i++)
    {
        a[i]=i+1;
        LinkStack_Push(stack,&a[i]);
    }

    int *ptmp=(int *)LinkStack_Top(stack);
    printf("len:%d\n",LinkStack_Size(stack));
    printf("top:%d\n",*ptmp);

    while(LinkStack_Size(stack)>0)
    {
        printf("pop:%d\n",*((int *)LinkStack_Pop(stack)));
    }
    LinkStack_Destroy(stack);
}
/*
typedef void LinkStack;
LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack, void* item);
void* LinkStack_Pop(LinkStack* stack);
void* LinkStack_Top(LinkStack* stack);
int LinkStack_Size(LinkStack* stack);
*/
