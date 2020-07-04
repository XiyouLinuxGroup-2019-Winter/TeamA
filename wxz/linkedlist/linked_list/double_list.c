/*************************************************************************
	> File Name: double_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 14时09分07秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_list.h"
typedef struct _tag_DLinkList{
    DLinkListNode head;
    DLinkListNode *slider;//游标
    int n;
}TDLinkList;

void* Create()
{
    int ret=0;
    TDLinkList* t=(TDLinkList*)malloc(sizeof(TDLinkList));
    if(t==NULL)
    {
        printf("内存开辟失败！\n");
        return NULL;
    }

    memset(t,0,sizeof(TDLinkList));

    t->head.next=NULL;
    t->head.pre=NULL;
    t->slider=NULL;
    t->n=0;
    return t;
}
void Destroy(void* list)
{
    TDLinkList* t=NULL;
    t=(TDLinkList*)list;
    if(list==NULL)
    {
        printf("结点销毁错误\n");
    }
    if(t!=NULL)
        free(t);

}
void Clear(void* list)
{
    TDLinkList* t=NULL;
    t=(TDLinkList*)list;
    if(list==NULL)
    {
        printf("函数无法清空\n");
    }
    t->head.next=NULL;
    t->head.pre=NULL;
    t->slider=NULL;
    t->n=0;
}
int Length(void* list)
{
    int ret=0;
    TDLinkList* t=NULL;
    t=(TDLinkList*)list;
    if(list==NULL)
    {
        ret=-1;
        printf("长度返回错误\n");
        return ret;
    }
    ret=t->n;
    return ret;
}
int Insert(void* list,DLinkListNode* node,int pos)
{
    int ret=0;
    TDLinkList* t=NULL;
    t=(TDLinkList*)list;
    DLinkListNode* pcur=NULL;
    DLinkListNode* pnext=NULL;
    if(list==NULL || node==NULL || pos<0)
    {
        ret=-1;
        printf("插入失败\n");
        return ret;
    }
    if(pos>t->n)
    {
        pos=t->n;
    }
    pcur=&(t->head);
    for(int i=0;i<pos;i++)
    {
        pcur=pcur->next;
    }
    pnext=pcur->next;
    pcur->next=node;
    node->next=pnext;
    if(pnext!=NULL)
    {
        pnext->pre=NULL;
    }
    node->pre=NULL;
    if(pcur!=(DLinkListNode*)t)
    {
        node->pre=pcur;
    }
    if(t->n==0)
    {
        t->slider=node;
    }
    t->n++;
    return ret;
}
DLinkListNode* Get(void* list,int pos)
{
    TDLinkList* t=(TDLinkList*)list;
    DLinkListNode* pcur=NULL;
    if(list==NULL || pos<0)
    {
        printf("获取结点错误!\n");
        return NULL;
    }
    pcur=&(t->head);
    for(int i=0;i<pos;i++)
    {
        pcur=pcur->next;
    }
    return pcur->next;
}
DLinkListNode* Delete_i(void* list,int pos)
{
    TDLinkList* t=(TDLinkList*)list;
    DLinkListNode* pcur=NULL;
    DLinkListNode* pafter=NULL;
    DLinkListNode* DeleteNode=NULL;
    if(list==NULL || pos<0)
    {
        printf("结点无法删除!\n");
        return NULL;
    }
    if(pos>Length(t))
    {
        pos=t->n;
    }
    pcur=&(t->head);
    for(int i=0;i<pos;i++)
    {
        pcur=pcur->next;
    }
    DeleteNode = pcur->next;
    pafter=DeleteNode->next;
    pcur->next=pafter;
    if(pafter!=NULL)
    {
        pafter->pre=pcur;
    }
    DeleteNode->pre=NULL;

    t->n--;

    if(t->slider==DeleteNode)
    {
        t->slider=pafter;
    }
    if(t->n==0)
    {
        t->head.next=NULL;
        t->head.pre=NULL;
        t->slider=NULL;
    }
    return DeleteNode;
}

DLinkListNode* Delete_key(void* list,DLinkListNode* node)
{
    TDLinkList* t=(TDLinkList*)list;
    DLinkListNode* pcur=NULL;
    DLinkListNode* DeleteNode=NULL;
    if(list==NULL || node==0)
    {
        printf("删除结点不存在!\n");
        return NULL;
    }
    pcur=&(t->head);

    int i;
    for(i=0;i<t->n;i++)
    {
        if(pcur->next==node)
        {
            DeleteNode=pcur->next;
            break;
        }
        pcur=pcur->next;
    }
    if(DeleteNode!=NULL)
    {
        Delete_i(t,i);
    }
    return DeleteNode;
}

DLinkListNode* SliderReset(void* list)
{
    TDLinkList* t=(TDLinkList*)list;

    DLinkListNode* tmp=NULL;
    if(list==NULL)
    {
        printf("指向第一个数据失败!\n");
        return NULL;
    }
    if(t!=NULL)
    {
        t->slider=t->head.next;
        tmp=t->slider;
    }
    return tmp;
}

DLinkListNode* SliderCurrent(void* list)
{
    TDLinkList* t=(TDLinkList*)list;
    DLinkListNode* tmp=NULL;
    if(list==NULL)
    {
        printf("获取游标指向数据失败！\n");
        return NULL;
    }
    if(t!=NULL)
    {
        tmp=t->slider;
    }
    return tmp;
}
DLinkListNode* SliderNext(void* list)
{
    TDLinkList* t=(TDLinkList*)list;

    DLinkListNode* tmp=NULL;
    if(list==NULL)
    {
        printf("移动游标到下一个数据失败\n");
        return NULL;
    }
    if(t!=NULL)
    {
        tmp=t->slider;
        t->slider=tmp->next;
    }
    return tmp;
}
DLinkListNode* SliderPre(void* list)
{
    TDLinkList* t=(TDLinkList*)list;
    DLinkListNode* tmp=NULL;
    if(list==NULL)
    {
        printf("游标移动指向到前一个数据失败!\n");
        return NULL;
    }
    if(t!=NULL)
    {
        tmp=t->slider;
        t->slider=tmp->pre;
    }
    return tmp;
}
