/*************************************************************************
	> File Name: doule_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 13时23分46秒
 ************************************************************************/

#ifndef _DOULE_LIST_H
#define _DOULE_LIST_H
typedef struct _tag_DLinkListNode{
    struct _tag_DLinkListNode* next;
    struct _tag_DLinkListNode* pre;
}DLinkListNode;

void* Create();
void Destroy(void* list);
void Clear(void* list);
int Length(void* list);
int Insert(void* list,DLinkListNode* node,int pos);
DLinkListNode* Get(void* list,int pos);
DLinkListNode* Delete_i(void* list,int pos);
DLinkListNode* Delete_key(void* list,DLinkListNode* node);
DLinkListNode* SliderReset(void* list);//重置游标到第一个元素
DLinkListNode* SliderCurrent(void* list);
DLinkListNode* SliderNext(void* list);
DLinkListNode* SliderPre(void* list);
#endif
