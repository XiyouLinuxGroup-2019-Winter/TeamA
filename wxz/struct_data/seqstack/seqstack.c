/*************************************************************************
	> File Name: seqstack.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月04日 星期一 21时04分53秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "seqstack.h"
#include "seqlist.h"
#include "seqlist.c"

SeqStack* SeqStack_Create(int capacity)
{
    return SeqList_Create(capacity);
}

void SeqStack_Destroy(SeqStack* stack)
{
    SeqList_Destroy(stack);
}
void SeqStack_Clear(SeqStack* stack)
{
    SeqList_Clear(stack);
}
//压入元素
int SeqStack_Push(SeqStack* stack, void* item)
{
    return SeqList_Insert(stack,item,SeqList_Length(stack)); 
}
void* SeqStack_Pop(SeqStack* stack)
{
    return SeqList_Delete(stack,SeqList_Length(stack)-1);
}
void* SeqStack_Top(SeqStack* stack)
{
    return SeqList_Get(stack,SeqList_Length(stack)-1);
}
int SeqStack_Size(SeqStack* stack)
{
    return SeqList_Length(stack);
}
int SeqStack_Capacity(SeqStack* stack)
{
    return SeqList_Capacity(stack);
}

/*SeqList* SeqList_Create(int capacity);
int  SeqList_Create01(SeqList **handle, int capacity);
void SeqList_Destroy(SeqList* list);
void SeqList_Clear(SeqList* list);
int SeqList_Length(SeqList* list);
int SeqList_Capacity(SeqList* list);
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);
SeqListNode* SeqList_Get(SeqList* list, int pos);
SeqListNode* SeqList_Delete(SeqList* list, int pos);
*/
