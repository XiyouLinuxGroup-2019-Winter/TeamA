/*************************************************************************
	> File Name: circlelist.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月02日 星期六 14时08分17秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "circlelist.h"
typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

CircleList* CircleList_Create()
{
    TCircleList* ret=(TCircleList*)malloc(sizeof(TCircleList));
    if(ret==NULL)
        return NULL;

    ret->length=0;
    ret->slider=NULL;
    ret->header.next=NULL;
    return ret;
}
void CircleList_Destroy(CircleList* list)
{
    if(list==NULL)
        return ;
    free(list);

}
void CircleList_Clear(CircleList* list)
{
    if(list==NULL)
        return ;
    TCircleList* slist=(TCircleList*)list;
    slist->length=0;
    slist->header.next=NULL;
    slist->slider=NULL;

}
int CircleList_Length(CircleList* list)
{
    TCircleList* slist = (TCircleList*)list;
	int ret = -1;
	if (list == NULL)
	{
		return ret;
	}
	ret = slist->length;
	return ret;
}
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
    int ret=0,i=0;
    TCircleList* slist=(TCircleList*)list;

    if(list==NULL || node==NULL || pos<0)
    {
        return -1;
    }

    //CircleListNode* current=(CircleListNode*)(&(slist->header));
    CircleListNode* current=(CircleListNode*)slist;

    for(i=0;(i<pos)&&(current->next!=NULL);i++)
    {
        current=current->next;
    }
    node->next=current->next;
    current->next=node;

    //如果第一次插入结点
    if(slist->length==0)
        slist->slider=node;

    slist->length++;

    //如果头插法
    if(current==(CircleListNode*)slist)
    {
        CircleListNode* last=CircleList_Get(slist,slist->length-1);
        last->next=current->next;
    }

    return ret;
}
CircleListNode* CircleList_Get(CircleList* list, int pos)
{
    int i=0;
    CircleListNode* ret=NULL;
    TCircleList* slist=(TCircleList*)list;
    if(list==NULL || pos<0)
        return NULL;

    CircleListNode* current=(CircleListNode*)slist;

    for(i=0;i<pos;i++)
    {
        current=current->next;
    }
    ret=current->next;
    return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
    TCircleList* slist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    int i=0;

    if((slist!=NULL)&&(pos>=0)&&(slist->length>0))
    {
        CircleListNode* current=(CircleListNode*)slist;
        CircleListNode* last=NULL;

        for(i=0;i<pos;i++)
        {
            current=current->next;
        }

        //如果删除第一个元素
        if(current==(CircleListNode*)slist)
        {
            last=CircleList_Get(slist,slist->length-1);
        }

        //要删除的元素
        ret=current->next;
        current->next=ret->next;

        slist->length--;

        if(last!=NULL)
        {
            slist->header.next=ret->next;
            last->next=ret->next;
        }

        if(slist->slider==ret)
        {
            slist->slider=ret->next;
        }

        if(slist->length==0)
        {
            slist->header.next=NULL;
            slist->slider=NULL;
        }
    }
    return ret;
}
//add

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
    TCircleList* slist=(TCircleList*)list;
    CircleListNode* ret=NULL;
    int i=0;

    if(slist!=NULL)
    {
        CircleListNode* current=(CircleListNode*)slist;
        for(i=0;i<slist->length;i++)
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
            CircleList_Delete(slist,i);
        }

    }
    return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
    TCircleList* slist=(TCircleList*)list;
    CircleListNode* ret=NULL;

    if(slist!=NULL)
    {
        slist->slider=slist->header.next;
        ret=slist->slider;
    }
    return ret;
}
CircleListNode* CircleList_Current(CircleList* list)
{
    TCircleList* slist=(TCircleList*)list;
	CircleListNode* ret=NULL;

	if(slist!=NULL)
	{
		ret=slist->slider;
	}

	return ret;
}
CircleListNode* CircleList_Next(CircleList* list)
{
    TCircleList* slist=(TCircleList*)list;
    CircleListNode* ret=NULL;

    if( (slist!=NULL) && (slist->slider!=NULL) )
	{
		ret=slist->slider;
		slist->slider=ret->next;
	}
	return ret;
}
