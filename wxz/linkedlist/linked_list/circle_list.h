/*************************************************************************
	> File Name: circle_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 21时17分08秒
 ************************************************************************/

#ifndef _CIRCLE_LIST_H
#define _CIRCLE_LIST_H
typedef struct _tag_CircleListNode{
    struct _tag_CircleListNode* next;
}CircleListNode;

void* Create();
void Destroy(void* list);
void Clear(void* list);
int Length(void* list);
int Insert(void* list,CircleListNode* node,int pos);
CircleListNode* Get(void* list,int pos);
CircleListNode* Delete_i(void* list,int pos);
CircleListNode* Delete_key(void* list,CircleListNode* node);
CircleListNode* SliderReset(void* list);
CircleListNode* SliderCurrent(void* list);
CircleListNode* SliderNext(void* list);







#endif
