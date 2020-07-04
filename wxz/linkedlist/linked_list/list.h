/*************************************************************************
	> File Name: list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月21日 星期五 14时36分17秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>
typedef struct LinkListNode{
    struct LinkListNode* next;
}LinkListNode;//小结点

typedef struct _Teacher{
	LinkListNode node;
	char name[32];
	int	age;
}Teacher;

void* Create();
void Destory(void* list);
void Init(void* list);
int Length(void* list);
int Insert(void* list,LinkListNode* node,int pos);
LinkListNode* AddFirst(void* list,LinkListNode* node,int pos);
LinkListNode* AddEnd(void* list,LinkListNode* node,int pos);
LinkListNode* Delete_i(void* list,int data);
int compare(void* a,void* b);
LinkListNode* Get(void* list,int pos);
void* Find_value(Teacher* tlist,void* value,int (*compare)(void* ,void* ));

#endif
