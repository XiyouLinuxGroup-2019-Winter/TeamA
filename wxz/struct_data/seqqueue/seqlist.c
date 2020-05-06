/*************************************************************************
	> File Name: seqlist.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 21时58分23秒
 ************************************************************************/

#include<stdio.h>
#include "seqlist.h"
#include <string.h>
#include <stdlib.h>

//结构体里面套一级指针
typedef struct _tag_Seqlist{
    int length;
    int capacity;
    //unsigned int* node;
    unsigned int** node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
    int ret=0;
    TSeqList* tmp=NULL;
    tmp=(TSeqList*)malloc(sizeof(TSeqList));
    if(tmp==NULL)
    {
        ret=-1;
        printf("func Seqlist_Create() error:%d\n",ret);
        return NULL;
    }
    memset(tmp,0,sizeof(tmp));

    //根据capacity的大小分配节点的空间
    tmp->node=(unsigned int**)malloc(sizeof(unsigned int*)*capacity);
    if(tmp->node==NULL)
    {
        ret=-2;
        printf("func Seqlist_Create() error:%d\n",ret);
        return NULL;
    }
    tmp->capacity=capacity;
    tmp->length=0;
    return tmp;
}
void SeqList_Destroy(SeqList* list)
{

    TSeqList* tlist=NULL;
    if(list==NULL)
    {
        return ;
    }
    tlist=(TSeqList*)list;
    if(tlist->node!=NULL)
    {
        free(tlist->node);
    }
    free(tlist);
    return ;
}
void SeqList_Clear(SeqList* list)
{

    TSeqList* tlist=NULL;
    if(list==NULL)
    {
        return ;
    }
    tlist=(TSeqList*)list;
    tlist->length=0;
    return ;
}
int SeqList_Length(SeqList* list)
{
    TSeqList* tlist=NULL;
    if(list==NULL)
    {
        return -1;
    }
    tlist=(TSeqList*)list;
    return tlist->length;

}
int SeqList_Capacity(SeqList* list)
{

    TSeqList* tlist=NULL;
    if(list==NULL)
    {
        return -1;
    }
    tlist=(TSeqList*)list;
    return tlist->capacity;
}
int SeqList_Insert(SeqList* list,SeqListNode* node,int pos)
{
    int i=0;
    TSeqList* tlist=(TSeqList*)list;

    if(list==NULL || node==NULL)
        return -1;

    if(tlist->length>=tlist->capacity)
        return -2;

    if(pos<0 || pos>=tlist->capacity)
        return -3;

    if(pos>=tlist->length)
        pos=tlist->length;

    for(i=tlist->length;i>pos;i--)
    {
        tlist->node[i]=tlist->node[i-1];
    }

    tlist->node[pos]=node;

    tlist->length++;
    return 0;
}
SeqListNode* SeqList_Get(SeqList* list,int pos)
{
    SeqListNode* ret=NULL;

    TSeqList* tlist=(TSeqList*)list;
    if(list==NULL || pos<0 || pos>=tlist->length)
        return NULL;

    ret=(SeqListNode*)tlist->node[pos];
    return ret;
}
SeqListNode* SeqList_Delete(SeqList* list,int pos)
{
    int i=0;
    SeqListNode* ret=NULL;
    TSeqList* tlist=(TSeqList*)list;
    if(list==NULL || pos<0 || pos>=tlist->length)
        return NULL;

    ret=(SeqListNode*)tlist->node[pos];


    for(i=pos+1;i<tlist->length;i++)
    {
        tlist->node[i-1]=tlist->node[i];
    }
    tlist->length--;
    return ret;
}



