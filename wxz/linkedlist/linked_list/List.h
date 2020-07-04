/*************************************************************************
	> File Name: List.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月23日 星期日 12时05分24秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>


/*
#include <assert.h>
#define LIST_POISON1 ((void *)0x00100100)
#define LIST_POISON2 ((void *)0x00200200)
struct list_head{
    struct list_head* pre,*next;
};
//初始化，带头结点的双向循环链表
//两中不一样的初始化方法
#define LIST_HEAD_INIT(name) {&(name),&(name)}
#define LIST_HEAD(name) \
        struct list_head name=LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head* list)
{
    list->pre=list;
    list->next=list;
}
//核心添加结点
static inline void _list_add(struct list_head* new,struct list_head* pre,list_head* next)
{
    next->pre=new;
    new->next=next;
    new->pre=pre;
    pre->next=new;
}
//头插法
static inline void list_add(struct list_head* new,struct list_head* head)
{
    _list_add(new,head,head->next);
}
//尾插法
static inline void list_add_tail(struct list_head* new,struct list_head* head)
{
    _list_add(new,head->pre,head);
}

//删除的核心算法
static inline void _list_del(struct list_head* pre,struct list_head* next)
{
    next->pre=pre;
    pre->next=next;
}
static inline void list_del(struct list_head* entry)
{
    _list_del(entry->pre,entry->next);
    entry->next=LIST_POISON1;
    entry->pre=LIST_POISON2;
}
static inline void list_del_init(struct list_head* entry)
{
    _list_del(entry->pre,entry->next);
    INIT_LIST_HEAD(entry);
}

//移动结点
//以头插法添加
static inline void list_move(struct list_head* list,struct list_head* head)
{
    _list_del(list->pre,list->next);
    list_add(list,head);
}

//移动结点以尾插法
static inline void list_move_tail(struct list_head* list,struct list_head* head)
{
    _list_del(list->pre,list->next);
    list_add_tail(list,head);
}

static inline void list_replace(struct list_head *old, struct list_head *new)
{
	new->next = old->next;
	new->pre= old->pre;
	new->next->pre = new;
	new->pre->next = new;
}
//替换节点,将旧节点初始化为新的链表
static inline void list_replace_init(struct list_head *old, struct list_head *new)
{
	list_replace(old, new);
    INIT_LIST_HEAD(old);
}



*/
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
