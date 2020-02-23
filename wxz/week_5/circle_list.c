/*************************************************************************
	> File Name: circle_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 22时33分58秒
 ************************************************************************/

#include<stdio.h>
#include "circle_list.h"
int Add(void* list,CircleListNode* node,int pos)
{
    int ret=0;
    int i=0;
    TCircleList* slist=(TCircleList*)list;
    if(list==NULL || node=NULL || pos<0)
    {
        return -1;
    }
    CircleListNode* current=(CircleListNode*)slist;
    for(o=0;(i<pos)&& (current->next!=NULL);i++)
    {
        current=current->next;
    }

    node->next=current->next;
    current->next=node;
    if(slist->n==0)
    {
        slist->slider=node;
    }
    slist->n++;

    if(current==(CircleListNode*)slist)
    {
        CircleListNode* last=Get(slist,slist->n-1);
        last->next=current->next;
    }
    return ret;
}

