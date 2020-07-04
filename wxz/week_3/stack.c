/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 15时23分53秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
Stack* STLInit()
{
    Stack* p;
    if(p=(Stack*)malloc(sizeof(Stack)))
    {
        p->top=0;
        return p;
    }
    return NULL;
}
int STLIsEmpty(Stack* SL)
{
    int t;
    t=(SL->top==0);
    return t;
}
int STLIsFull(Stack* SL)
{
    int t;
    t=(SL->top==maxlen);
    return t;
}
void STLClear(Stack* SL)
{
    SL->top=0;
}
void STLFree(Stack* SL)
{
    if(SL)
    free(SL);
}
int PushSTL(Stack* SL,DATA data)
{
    if((SL->top+1)>maxlen)
    {
        printf("栈溢出!\n");
        return 0;
    }
    SL->data[++SL->top]=data;
}
DATA PopSTL(Stack* SL)
{
    if(SL->top==0)
    {
        printf("栈为空!\n");
        exit(1);
    }
    return (SL->data[SL->top--]);
}

DATA PeeckSTL(Stack* SL)
{
    if(SL->top==0)
    {
        printf("栈为空！\n");
        exit(0);
    }
    return (SL->data[SL->top]);
}
//读结点数据

