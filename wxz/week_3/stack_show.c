/*************************************************************************
	> File Name: stack_show.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 17时49分38秒
 ************************************************************************/

#include<stdio.h>
#include "stack.h"
int main()
{
    Stack*SL;
    DATA data1,data;

    SL=STLInit();
    printf("入栈操作:\n");
    printf("输入姓名　年龄进行入栈操作:");
    do{
        scanf("%s %d",data.name,&data.age);
        if(strcmp(data.name,"0")==0)
            break;
        else
            PushSTL(SL,data);
    }while(1);

    do{
        printf("\n出栈操作：");
        getchar();
        data1=PopSTL(SL);
        printf("出栈的数据是%s %d\n",data1.name,&data1.age);
    }while(1);
    STLFree(SL);
}
