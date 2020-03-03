/*************************************************************************
	> File Name: circle_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 21时33分47秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circle_list.h"

typedef struct _tag_CircleList{
    CircleListNode head;
    CircleListNode* slider;
    int n;
}TCircleList;

void* Create()
{
    TCircleList* ret=(TCircleList*)malloc(sizeof(TCircleList));
    if(ret==NULL)
        return NULL;
    memset(ret,0,sizeof(TCircleList));
    ret->n=0;
    ret->head.next=NULL;
    ret->slider=NULL;
    return ret;
}
void Destroy(void* list)
{
    if(list==NULL)
    {
        return ;
    }
    free(list);
}
void Clear(void* list)
{
    TCircleList* tlist=(TCircleList*)list;
    if(tlist==NULL)
    {
        return ;
    }
    tlist->n=0;
    tlist->head.next=NULL;
    tlist->slider=NULL;
}
int Length(void *list)
{
    TCircleList* tlist=(TCircleList*)list;
    int ret=-1;
    if(tlist==NULL)
    {
        return ret;
    }
    ret=tlist->n;
    return ret;
}
int Insert(void* list,CircleListNode* node,int pos)
{
    int ret=0;
    int i=0;
    TCircleList* tlist=(TCircleList*)list;

    if(tlist==NULL || node== NULL || pos<0)
    {
        return -1;
    }
    CircleListNode* current=(CircleListNode*)tlist;

    for(i=0;(i<pos)&& (current->next!=NULL);i++)
    {
        current=current->next;
    }

    node->next=current->next;
    current->next=node;

    //第一次插入结点
    if(tlist->n==0)
    {
        tlist->slider=node;
    }
    tlist->n++;

    //头插法
    if(current==(CircleListNode*)tlist)
    {
        //获取最后一个元素
        CircleListNode* last=Get(tlist,tlist->n-1);
        last->next=current->next;
    }
    return ret;
}
CircleListNode* Get(void* lis,int pos)
{
    TCircleList* list=(TCircleList*)list;
    CircleListNode* ret=NULL;
    int i=0;
    if(list==NULL || pos<0)
        return NULL;

    CircleListNode* current=(CircleListNode*)list;
    for(i=0;i<pos;i++)
    {
        current=current->next;
    }
    ret=current->next;

    return ret;
}
CircleListNode* Delete_i(void* list,int pos)
{
    TCircleList* tlist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    int i=0;

    if((list!=NULL)&& (pos>0) && (tlist->n>0))
    {
        CircleListNode* current=(CircleListNode*)tlist;
        CircleListNode* last=NULL;

        for(i=0;i<pos;i++)
        {
            current=current->next;
        }
        //删除第一个元素
        if(current==(CircleListNode*)tlist)
        {
            last=(CircleListNode*)Get(tlist,tlist->n-1);
        }

        //要删除的元素
        ret=current->next;
        current->next=ret->next;
        tlist->n--;

        if(last!=NULL)
        {
            tlist->head.next=ret->next;
            last->next=ret->next;
        }

        //删除游标所指的元素
        if(tlist->slider==ret)
        {
            tlist->slider=ret->next;    
        }

        //删除元素后，长度为0
        if(tlist->n==0)
        {
            tlist->head.next=NULL;
            tlist->slider=NULL;
        }
    }
    return ret;
}
CircleListNode* Delete_key(void* list,CircleListNode* node)
{
    TCircleList* tlist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    int i=0;
    if(tlist!=NULL)
    {
        CircleListNode* current=(CircleListNode*)tlist;

        //node的位置
        for(i=0;i<tlist->n;i++)
        {
            if(current->next==node)
            {
                ret=current->next;
                break;
            }
            current=current->next;
        }
        if(ret!=NULL)
        {
            Delete_i(tlist,i);
        }
    }
    return ret;
}
CircleListNode* SliderReset(void* list)
{
    TCircleList* tlist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    if(tlist!=NULL)
    {
        tlist->slider=tlist->head.next;
        ret=tlist->slider;
    }
    return ret;
}
CircleListNode* SliderCurrent(void* list)
{
    TCircleList* tlist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    if(tlist!=NULL)
    {
        ret=tlist->slider;
    }
    return ret;
}
CircleListNode* SliderNext(void* list)
{
    TCircleList* tlist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    if(tlist!=NULL && (tlist->slider!=NULL))
    {
        ret=tlist->slider;
        tlist->slider=ret->next;
    }
    return ret;
}

