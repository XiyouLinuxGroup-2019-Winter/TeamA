/*************************************************************************
	> File Name: linkqueue.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 22时11分36秒
 ************************************************************************/

#include<stdio.h>
#include "linklist.h"
#include "linklist.c"
#include "linkqueue.h"

typedef struct _tag_LinkQueueNode{
    LinkListNode node;
    void* item;
}TLinkQueueNode;


LinkQueue* LinkQueue_Create()
{
    return LinkList_Create();
}
void LinkQueue_Destroy(LinkQueue* queue)
{
    LinkQueue_Clear(queue);
    LinkList_Destroy(queue);
}
void LinkQueue_Clear(LinkQueue* queue)
{
    while(LinkList_Length(queue)>0)
    {
        LinkQueue_Retrieve(queue);
    }
    LinkList_Clear(queue);
    return ;
}

int LinkQueue_Append(LinkQueue* queue, void* item)
{
    TLinkQueueNode* tmp=NULL;
    int ret=0;
    tmp=(TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
    if(tmp==NULL)
    {
        ret=-1;
        return ret;
    }
    memset(tmp,0,sizeof(TLinkQueueNode));
    
    tmp->item=item;

    ret=LinkList_Insert(queue,(LinkListNode*)tmp,LinkList_Length(queue));
    if(ret!=0)
    {
        if(tmp!=NULL)
            free(tmp);
        return ret;
    }
    return ret;
}
void* LinkQueue_Retrieve(LinkQueue* queue)
{
    TLinkQueueNode* tmp=NULL;
    void* ret=NULL;
    tmp=(TLinkQueueNode*)LinkList_Delete(queue,0);
    if(tmp==NULL)
    {
        return NULL;
    }

    //删除之前缓存
    ret=tmp->item;
    if(tmp!=NULL);
        free(tmp);

    return ret;
}

void* LinkQueue_Header(LinkQueue* queue)
{
    TLinkQueueNode* tmp=NULL;
    void* ret=NULL;

    tmp=(TLinkQueueNode*)LinkList_Get(queue,0);
    if(tmp==NULL)
    {
        return NULL;
    }
    return tmp->item;
}

int LinkQueue_Length(LinkQueue* queue)
{
    return LinkList_Length(queue);
}
/*
LinkList* LinkList_Create();
void LinkList_Destroy(LinkList* list);
void LinkList_Clear(LinkList* list);
int LinkList_Length(LinkList* list);
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
LinkListNode* LinkList_Get(LinkList* list, int pos);
LinkListNode* LinkList_Delete(LinkList* list, int pos);*/

