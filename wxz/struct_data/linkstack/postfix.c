/*************************************************************************
	> File Name: postfix.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月05日 星期二 13时55分58秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkstack.h"
#include "linkstack.c"
int isLeft(char c);
int isRight(char c);
int match(char left,char right);
int scanner(const char* code);
#include "stdio.h"
#include "stdlib.h"
#include "linkstack.h"

int isLeft(char c)
{
    int ret=0;
    switch(c)
	{
	    case '<':
	    case '(':
	    case '[':
	    case '{':
	    case '\'':
	    case '\"':
		    ret=1;
		    break;
	    default:
		    ret=0;
		    break;
	}
	return ret;
}
int isRight(char c)
{
	int ret=0;

	switch(c)
	{
	    case '>':
	    case ')':
	    case ']':
	    case '}':
	    case '\'':
	    case '\"':
		    ret=1;
		    break;
	    default:
		    ret=0;
		    break;
	}
	return ret;
}
int match(char left, char right)
{
	int ret = 0;

	switch(left)
	{
	case '<':
		ret=(right=='>');
		break;
	case '(':
		ret=(right==')');
		break;
	case '[':
		ret=(right==']');
		break;
	case '{':
		ret=(right=='}');
		break;
	case '\'':
		ret=(right=='\'');
		break;
	case '\"':
		ret=(right=='\"');
		break;
	default:
		ret=0;
		break;
	}
	return ret;
}
int scanner(const char* code)
{
    LinkStack* stack=LinkStack_Create();
    int ret=0,i=0;
    while(code[i]!='\0')
    {
        if(isLeft(code[i]))
        {
            LinkStack_Push(stack,(void*)(code+i));
        }
        if(isRight(code[i]))
        {
            char* c=(char*)LinkStack_Pop(stack);
            if((c==NULL) || !match(*c,code[i]))
            {
                printf("%c does not match!\n",code[i]);
                ret=0;
                break;
            }
        }
        i++;
    }
    if(LinkStack_Size(stack)==0 &&(code[i]=='\0'))
    {
        printf("succeed!\n");
        ret=1;
    }
    else
    {
        printf("invalid code!\n");
        ret=0;
    }
    LinkStack_Destroy(stack);
    return ret;
}
int main()
{
    const char* code = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0; ";
    scanner(code);
}
/*LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack, void* item);
void* LinkStack_Pop(LinkStack* stack);
void* LinkStack_Top(LinkStack* stack);
int LinkStack_Size(LinkStack* stack);*/

