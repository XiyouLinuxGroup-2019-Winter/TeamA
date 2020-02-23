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
}LinkListNode;

typedef struct Main{
    LinkListNode node;//小节点
    int data;
}Main;

typedef  struct LinkList{
    int n;
    LinkListNode head;
}TLinkList;//头结点


void* Create();
void Destory(void* list);
void Init(void* list);
int Length(void* list);
int Add(void* list,LinkListNode* node,int data);
LinkListNode* Delete(void* list,int data);
#endif
