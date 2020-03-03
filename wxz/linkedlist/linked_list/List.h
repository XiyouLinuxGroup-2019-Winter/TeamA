/*************************************************************************
	> File Name: List.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月23日 星期日 12时05分24秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>
#include <assert.h>

//初始化，带头结点的双向循环链表
#define Init(list,list_node_t) {      \
            list=(list_node_t*)malloc(sizeof(list_node_t));\
            list->next=list->pre=list; \
}
//释放结点，list为链表头指针
#define Free(list, list_node_t) {			\
		assert(list!=NULL);						\
		list_node_t *tmp;					\
		list->pre->next=NULL; 				\
		while((tmp=list->next)!=NULL){ 	\
			list->next=tmp->next;			\
			free(tmp);						\
		}										\
		list->next=list->pre=list;			\
	}

//销毁链表
#define Destroy(list,list_node_t) {          \
            assert(list!=NULL);             \
            Free(list);                     \
            list=NULL;                      \
}
//头插法
#define Add_head(list,newnode) {                  \
            newnode->next=list->next;       \
            list->next->pre=newnode;        \
            newnode->pre=list;              \
            list->next=newnode;             \
}
//尾插法
#define Add_tail(list,newnode) {            \
            newnode->next=list->next;       \
            list->next->pre=newnode;        \
            newnode->pre=list;              \
            list->next=newnode;             \
}
//将新结点newnode加入到node之前
#define AddBefore(node,newnode) {           \
            newnode->pre=node->pre;         \
            newnode>next=node;              \
            newnode->pre->next=newnode;     \
            newnode->next->pre=newnode;     \
}
//将新结点newnode加入到node之后
#define AddAfter(node,newnode) {            \
            newnode->next=node->next;       \
            newnode->pre=node;              \
            newnode->next->pre=newnode;     \
            newnode->pre->next=newnode;     \
}
//判断链表是否为空,list为头指针
#define List_Is_Empty(list) ((list!=NULL)   \
            && (list->next==list)            \
            && (list->pre==list))
//删除结点node
#define Delete(node) {                      \
            assert(node!= NULL && node!=node->next && node!=node->pre); \
            node->pre->next=node->next;     \
            node->next->pre=node->pre;     \
}
//删除并释放node
#define FreeNode(node) {                  \
            Delete(node);                 \
            free(node);                   \
}
//使用指针curpos依次历遍链表list
#define Print(list,curpos)               \
        for(curpos=list->next;curpos!=list;curpos=curpos->next)   \
#endif
