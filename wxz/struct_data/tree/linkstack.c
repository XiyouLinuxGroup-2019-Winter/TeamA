/*************************************************************************
	> File Name: linkstack.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 16时52分54秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.c"
#include "linkstack.h"
#include "linklist.h"
typedef struct _tag_LinkStackNode
{
	LinkListNode node; //占位结构。。。只要定义一个和node节大小一样的数据即可
	void *item;
}TLinkStackNode;

LinkStack* LinkStack_Create()
{
    return LinkList_Create();
}
void LinkStack_Destroy(LinkStack* stack)
{
    LinkStack_Clear(stack);
    LinkList_Destroy(stack);
}
void LinkStack_Clear(LinkStack* stack)
{
    if(stack==NULL)
        return ;
    while(LinkStack_Size(stack)>0)
    {
        LinkStack_Pop(stack);
    }
    return ;
}
int LinkStack_Push(LinkStack* stack, void* item)
{
    TLinkStackNode* tmp=(TLinkStackNode*)malloc(sizeof(TLinkStackNode));
    int ret=0;
    if(tmp==NULL)
        return -1;

    memset(tmp,0,sizeof(TLinkStackNode));

    tmp->item=item;

    ret=LinkList_Insert(stack,(LinkListNode*)tmp,0);

    if(ret!=0)
    {
        printf("func LinkList_Insert error:%d\n",ret);
        if(tmp!=NULL)
            free(tmp);
        return ret;
    }
    return ret;
}
void* LinkStack_Pop(LinkStack* stack)
{
    void *item=NULL;
    TLinkStackNode* tmp=(TLinkStackNode*)LinkList_Delete(stack,0);
    if(tmp==NULL)
        return NULL;

    item=tmp->item;
    free(tmp);
    return item;
}
void* LinkStack_Top(LinkStack* stack)
{
    void* item;
    TLinkStackNode* tmp=(TLinkStackNode*)LinkList_Get(stack,0);
    if(tmp==NULL)
        return NULL;

    return tmp->item;
}
int LinkStack_Size(LinkStack* stack)
{
    return LinkList_Length(stack);
}
