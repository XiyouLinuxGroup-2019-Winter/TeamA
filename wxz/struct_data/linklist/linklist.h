/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 17时37分30秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H
typedef void LinkList;
/*
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
	LinkListNode* next;
};
*/
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;


LinkList* LinkList_Create();
void LinkList_Destroy(LinkList* list);
void LinkList_Clear(LinkList* list);
int LinkList_Length(LinkList* list);
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
LinkListNode* LinkList_Get(LinkList* list, int pos);
LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif
