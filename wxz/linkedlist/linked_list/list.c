/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 00时54分42秒
 ************************************************************************/

#include<stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>
typedef struct LinkList{
    int n;
    LinkListNode head;
}TLinkList;//大结点

void* Create()
{
    TLinkList* ret;
    ret=(TLinkList*)malloc(sizeof(TLinkList));
    memset(ret,0,sizeof(TLinkList));
    ret->n=0;
    ret->head.next=NULL;
    return ret;
}
int Insert(void* list,LinkListNode* node,int pos)
{
    int ret=0;
    TLinkList* t=(TLinkList*)list;
    LinkListNode* current=NULL;
    if (NULL == t||NULL == node || pos < 0)
	{
		ret=-1;
		printf("加入数据失败！\n");
		return ret;
	}
    current=&(t->head);

    
	for(int i=0;i<pos;i++)
	{
		current=current->next;
	}
	node->next =current->next;
	current->next = node;
	t->n++;
	return ret;    
}
LinkListNode* AddFirst(void* list,LinkListNode* node,int pos)
{
    int i=0;
    //int ret=0;
    LinkListNode* current=NULL;

    TLinkList* tlist=(TLinkList*)list;
    if(list==NULL || node==NULL || pos<0)
    {
        printf("结点返回错误");
        return NULL;
    }

    current=&(tlist->head);
    
    for(i=0;i<pos;i++)
    {
        current=current->next;
    }

    node->next=current->next;
    current->next=node;
    
    tlist->n++;
    return &(tlist->head);
}
LinkListNode* AddEnd(void* list,LinkListNode* node,int pos)
{
    int i;
    LinkListNode* current=NULL;
    TLinkList* tlist=(TLinkList*)list;
    TLinkList* tail=tlist;
    
    if(list==NULL || node==NULL || pos<0)
    {
        printf("结点错误");
        return NULL;
    }
    current=&(tail->head);
    for(i=0;i<pos;i++)
    {
        current=current->next;
    }
    node->next=tail->head.next;
    tail->head.next=node;
    current=tail->head.next;
    tlist->n++;
    
    return &(tlist->head);
}
void Destory(void* list)
{
    TLinkList* t=(TLinkList*)list;
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
    //int t=0;
    LinkListNode* current=NULL;

    LinkListNode* ret=NULL;
    TLinkList* tlist=(TLinkList*)list;

    if(list==NULL || pos<0)
    {
        //t=-1;
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
    return ret;//返回删除的该结点
}
LinkListNode* Get(void* list,int pos)
{
    int i;
    LinkListNode* current=NULL;
    TLinkList* tlist=(TLinkList*)list;

    if(list==NULL || pos<0)
    {
        printf("该结点不存在\n");
        return NULL;
    }
    current=&(tlist->head);
    for(i=0;i<pos;i++)
    {
        current=current->next;
    }
    return current->next;
}
void* Find_value(Teacher* tlist,void* value,int (* compare)(void*, void* ))
{
    LinkListNode* current=NULL;
    current=(&tlist->node);
    while(current->next!=NULL)
    {
        if(compare(&tlist->age,value)==0)
            break;
        current=current->next;
    }
}
int compare(void* a,void* b)
{
    if(*(int*)a==*(int*)b)
        return 0;
    else
        return 1;
}
/*LinkListNode* Delete_value(Main* tlist,void* value,int (* compare)(void* ,void* ))
{
    LinkListNode* current=tlist->node;
    LinkListNode* q;//中间变量q保存结点
    while(tlist->node.next!=NULL)
    {
        if(compare(&tlist->data,value)==0)
        {
            q=current->next;
            current->next=q->next;
            free(q);
        }
        tlist=tlist->node.next;
    }
    return (&tlist->node);
}*/

