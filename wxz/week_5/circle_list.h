/*************************************************************************
	> File Name: circle_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 22时34分45秒
 ************************************************************************/

#ifndef _CIRCLE_LIST_H
#define _CIRCLE_LIST_H
typedef struct CircleListNode{
    struct CircleList* next;
}CircleListNode;

typedef struct tag_CirleList{
    CircleList head;
    CircleList* slider;
    int n;
}TCircleList;

void Destroy(void* list);
void Init(void* list);
int Length(void* list);
int Add(void* list,CircleListNode* node,int pos);
CircleListNode* Delete(void* list,int pos);
CircleListNode* Delete(void* list,CircleListNode* node);

CircleListNode* Get(void* list,int pos);

CircleListNode* Reset(void* list);
CircleListNode* Current(void* list);
CircleListNode* Next(void* list);

#endif
