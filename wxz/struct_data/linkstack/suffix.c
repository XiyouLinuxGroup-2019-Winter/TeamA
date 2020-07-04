/*************************************************************************
	> File Name: suffix.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时17分29秒
 ************************************************************************/

#include<stdio.h>
#include "linkstack.h"
#include "linkstack.c"
#include <stdlib.h>
int isNumber(char c);
int isOperate(char c);
int value(char c);
int express(int left,int right,char op);
int compute(const char* exp);

int isNumber(char c)
{
    return (c<='9') &&(c>='0');
}
int isOperate(char c)
{
    return (c=='+') || (c=='-') || (c=='*') || (c=='/');
}
int value(char c)
{
    return (c-'0');
}
int express(int left,int right,char op)
{
    int ret=0;
    switch(op)
    {
        case '+':
            ret=left+right;
            break;
        case '-':
            ret=left-right;
            break;
        case '*':
            ret=left*right;
            break;
        case '/':
            ret=left/right;
            break;
        default:
            break;
    }
    return ret;
}
int compute(const char* exp)
{
    LinkStack* stack=LinkStack_Create();
    int ret=0;
    int i=0;

    while(exp[i]!='\0')
    {
        if(isNumber(exp[i]))
        {
            LinkStack_Push(stack,(void*)value(exp[i]));
        }
        else if(isOperate(exp[i]))
        {
            int right=(int)LinkStack_Pop(stack);
            int left=(int)LinkStack_Pop(stack);
            int result=right+left;
            LinkStack_Push(stack,(void*)result);
        }
        else
        {
            printf("Invalid expression\n");
            break;
        }
        i++;
    }
    if((LinkStack_Size(stack)==1)&& (exp[i]=='\0'))
    {
        ret=(int)LinkStack_Pop(stack);
    }
    else
        printf("Invalid expression!\n");

    LinkStack_Destroy(stack);
    return ret;
}

int main()
{
    printf("8 + (3 - 1) * 5  = %d\n", compute("831-5*+"));
}
/*LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack, void* item);
void* LinkStack_Pop(LinkStack* stack);
void* LinkStack_Top(LinkStack* stack);
int LinkStack_Size(LinkStack* stack);*/
