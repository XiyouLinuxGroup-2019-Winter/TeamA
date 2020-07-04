/*************************************************************************
	> File Name: linklist.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 17时40分50秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"
typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

LinkList* LinkList_Create()
{
    TLinkList* ret=NULL;

    ret=(TLinkList*)malloc(sizeof(TLinkList));
    memset(ret,0,sizeof(TLinkList));
    ret->length=0;
    ret->header.next=NULL;

    return ret;
}
void LinkList_Destroy(LinkList* list)
{
    if(list!=NULL)
    {
        free(list);
        list=NULL;
    }
    return ;
}
void LinkList_Clear(LinkList* list)
{
   TLinkList* tlist=NULL;
    if(list==NULL)
        return ;

    tlist=(TLinkList*)list;

    tlist->length=0;
    tlist->header.next=NULL;
    return ;
}
int LinkList_Length(LinkList* list)
{

   TLinkList* tlist=NULL;
    if(list==NULL)
        return -1;

    tlist=(TLinkList*)list;
    return tlist->length;

}
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
    int ret=0;
    int i=0;
    LinkListNode* current=NULL;

    TLinkList* tlist=NULL;
    if(list==NULL || node==NULL || pos<0)
    {
        ret=-1;
        printf("func erro:%d\n",ret);
        return ret;
    }
    tlist=(TLinkList*)list;
    current=&(tlist->header);

    for(i=0;i<pos&&(current->next!=NULL);i++)
    {
        current=current->next;
    }

    //插入算法
    node->next=current->next;
    current->next=node;
    
    tlist->length++;
    return 0;
}
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
    int ret=0;
    int i=0;
    LinkListNode* current=NULL;

    TLinkList* tlist=NULL;
    if(list==NULL || pos<0)
    {
        ret=-1;
        printf("func erro:%d\n",ret);
        return NULL;
    }
    tlist=(TLinkList*)list;
    current=&(tlist->header);

    for(i=0;i<pos&&(current->next!=NULL);i++)
    {
        current=current->next;
    }

    return current->next;
}
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
    
    int i=0;
    LinkListNode* current=NULL;
    LinkListNode* ret=NULL;

    TLinkList* tlist=NULL;
    if(list==NULL || pos<0)
    {
       
        printf("func erro:%d\n",ret);
        return NULL;
    }
    tlist=(TLinkList*)list;
    current=&(tlist->header);

    for(i=0;i<pos&&(current->next!=NULL);i++)
    {
        current=current->next;
    }

    ret=current->next;
    current->next=ret->next;

    tlist->length--;

    return ret;
}
