/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月04日 星期一 21时32分49秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "seqstack.h"
int main()
{ 
    SeqStack* stack=SeqStack_Create(10);
    int i=0;
    int a[10];
    if(stack==NULL)
        return -1;

    //压栈
    for(i=0;i<5;i++)
    {
        a[i]=i+1;
        SeqStack_Push(stack,&a[i]);
    }

    int *ptmp = (int *)SeqStack_Top(stack);
    printf("capacity:%d\n",SeqStack_Capacity(stack));
    printf("length:%d\n",SeqStack_Size(stack));
    printf("top:%d\n",*ptmp);

    while(SeqStack_Size(stack)>0)
	{
		printf("pop:%d\n",*((int *)SeqStack_Pop(stack)));
	}


}

/*SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);*/

