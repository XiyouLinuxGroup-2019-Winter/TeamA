/*************************************************************************
	> File Name: seqlist.h
	> Author: 
	> Mail: 
	> Created Time: 2020年05月04日 星期一 23时00分36秒
 ************************************************************************/

#ifndef _SEQLIST_H
#define _SEQLIST_H
typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);
int  SeqList_Create01(SeqList **handle, int capacity);
void SeqList_Destroy(SeqList* list);
void SeqList_Clear(SeqList* list);
int SeqList_Length(SeqList* list);
int SeqList_Capacity(SeqList* list);
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);
SeqListNode* SeqList_Get(SeqList* list, int pos);
SeqListNode* SeqList_Delete(SeqList* list, int pos);
#endif
