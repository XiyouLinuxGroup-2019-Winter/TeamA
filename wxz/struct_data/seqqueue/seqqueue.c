/*************************************************************************
	> File Name: seqqueue.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 21时45分46秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "seqqueue.h"
#include "seqlist.h"
#include "seqlist.c"

SeqQueue* SeqQueue_Create(int capacity)
{
    return SeqList_Create(capacity);
}
void SeqQueue_Destroy(SeqQueue* queue)
{
    return SeqList_Destroy(queue);
}
void SeqQueue_Clear(SeqQueue* queue)
{
    return SeqList_Clear(queue);
}
int SeqQueue_Append(SeqQueue* queue, void* item)
{
    return SeqList_Insert(queue,item,SeqList_Length(queue));
}
void* SeqQueue_Retrieve(SeqQueue* queue)
{
    return SeqList_Delete(queue,0);
}
void* SeqQueue_Header(SeqQueue* queue)
{
    return SeqList_Get(queue,0);
}
int SeqQueue_Length(SeqQueue* queue)
{
    return SeqList_Length(queue);
}
int SeqQueue_Capacity(SeqQueue* queue)
{
    return SeqList_Capacity(queue);
}
/*
SeqList* SeqList_Create(int capacity);
int  SeqList_Create01(SeqList **handle, int capacity);
void SeqList_Destroy(SeqList* list);
void SeqList_Clear(SeqList* list);
int SeqList_Length(SeqList* list);
int SeqList_Capacity(SeqList* list);
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);
SeqListNode* SeqList_Get(SeqList* list, int pos);
SeqListNode* SeqList_Delete(SeqList* list, int pos);
*/
