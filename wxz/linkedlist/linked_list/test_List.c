/*************************************************************************
	> File Name: test_List.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 13时49分37秒
 ************************************************************************/

#include<stdio.h>
#include "List.h"
/*struct list_head		
{
	struct list_head *pre, *next;
};
#define LIST_HEAD_INIT(name) {&(name), &(name)}
#define LIST_HEAD(name)	\
	struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->pre = list;
	list->next = list;
}*/
int main()
{
    LIST_HEAD(t);
    printf("pre:%x next:%x\n",t.pre,t.next);
    struct list_head t2;
    INIT_LIST_HEAD(&t2);
    printf("pre:%x next:%x\n",t2.pre,t2.next);
}
