/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 00时54分42秒
 ************************************************************************/

#include<stdio.h>
#include "list.h"
void* Create()
{
    TLinkList* ret;
    ret=(TLinkList*)malloc(sizeof(TLinkList));
    ret->n=0;
    ret->head.next=NULL;
    return ret;
}
int Add(void* list,LinkListNode* node,int pos)
{
    int i=0;
    int ret=0;
    LinkListNode* current=NULL;

    TLinkList* tlist=(TLinkList*)list;
    if(list==NULL || node==NULL || pos<0)
    {
        ret=-1;
        printf("结点返回错误");
        return ret;
    }

    current=&(tlist->head);
    
    for(i=0;i<pos;i++)
    {
        current=current->next;
    }

    node->next=current->next;
    current->next=node;
    
    return 0;
}
void Destory(void* list)
{
    if(list!=NULL)
    {
        free(list);
        list=NULL;
    }
    return ;
}
void Init(void* list)
{
    TLinkList *tlist=NULL;
    if(list==NULL)
        return ;
    tlist=(TLinkList*)list;
    tlist->n=0;
    tlist->head.next=NULL;
    return ;
}
int Length(void* list)
{
    TLinkList* tlist=NULL;
    if(list==NULL)
        return -1;
    tlist=(TLinkList*)list;
    return tlist->n;
}
LinkListNode* Detele(void* list,int pos)
{
    int i;
    int t=0;
    LinkListNode* current=NULL;

    LinkListNode* ret=NULL;
    TLinkList* tlist=(TLinkList*)list;

    if(list==NULL || pos<0)
    {
        t=-1;
        return NULL;
    }
    current=&(tlist->head);
    for(i=0;i<pos;i++)
    {
        current=current->next;
    }
    ret=current->next;
    current->next=ret->next;
    tlist->n--;
    return ret;
}
