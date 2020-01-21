#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>
Status InitLInkList(Plist *p)
{
    Pnode m, n;
    if (((m = (Pnode)malloc(sizeof(Lnode))) != NULL) && (n = (Pnode)malloc(sizeof(Lnode))) != NULL)
    {
        m->next = n;
        m->pre = n;
        n->next = m;
        n->pre = m;
        (*p)->sum_node = 0;
        (*p)->head = m;
        (*p)->tail = n;
        return OK;
    }
    else
        return FALSE;
}
Status AddNode_head(Plist *p, elem_type e)
{
    Pnode cur;
    if ((cur = (Pnode)malloc(sizeof(Lnode))) != NULL)
    {

        cur->data = e;
        cur->next = (*p)->head->next;
        ;
        cur->pre = (*p)->head;
        cur->next->pre = cur;
        (*p)->head->next = cur;
        (*p)->sum_node++;
        return OK;
    }
    else
        return FALSE;
}
Status AddNode_tail(Plist *p, elem_type e)
{
    Pnode cur;
    if ((cur = (Pnode)malloc(sizeof(Lnode))) != NULL)
    {
        cur->data = e;
        cur->next = (*p)->tail;
        cur->pre = (*p)->tail->pre;
        cur->pre->next = cur;
        (*p)->tail->pre = cur;
        (*p)->sum_node++;
        return OK;
    }
    else
        return FALSE;
}
Status DeleteNode_num(Plist *p, int n, elem_type *e)
{
    Pnode m = (*p)->head;
    if (n > (*p)->sum_node || n <= 0)
        return FALSE;
    else
    {
        while (n)
        {
            m = m->next;
            n--;
        }
        *e = m->data;
        m->pre->next = m->next;
        m->next->pre = m->pre;
        free(m);
        (*p)->sum_node--;
    }
    return OK;
}
Status DeleteNode_key(Plist *p, elem_type e)
{
    Pnode temp, m = (*p)->head->next;
    if (m == (*p)->tail)
        return FALSE;
    while (m != (*p)->tail)
    {
        temp = m->next;
        if (m->data == e)
        {
            m->pre->next = m->next;
            m->next->pre = m->pre;
            free(m);
            (*p)->sum_node--;
        }
        m = temp;
    }

    return OK;
}
Status ChangeNode_key(Plist *p, elem_type *e, elem_type cur)
{
    Pnode m = (*p)->head->next;
    // elem_type temp;
    if (!SeekNode_key(p, cur))
        return FALSE;
    while (m != (*p)->tail)
    {
        if (m->data == *e)
        {
            m->data = cur;
        }
        m = m->next;
    }
    return OK;
}
Status SeekNode_num(Plist *p, int n, elem_type *e)
{
    Pnode m = (*p)->head;
    if (n > (*p)->sum_node || n <= 0)
        return FALSE;
    else
    {
        while (n)
        {
            m = m->next;
            n--;
        }
        *e = m->data;
    }
    return OK;
}
Status SeekNode_key(Plist *p, elem_type e)
{
    Pnode m = (*p)->head;
    while (m != (*p)->tail && m->data != e)
    {
        m = m->next;
    }
    if (m == (*p)->tail)
        return FALSE;
    else
        return OK;
}
void SeekNode_this(Lnode *this)
{
    printf("%d\n", this->data);
}
Status Traverse(Plist *p, void (*fun)(Lnode *this))
{
    Lnode *temp = (*p)->head->next;
    printf("~~~~~\n");
    while (temp != (*p)->tail)
    {
        fun(temp);
        temp = temp->next;
    }
    printf("~~~~~\n");
}
void menu(Plist*p)
{
    int choice;
    puts("1>头插\t2>尾插");
    puts("3>以项数删除\t4>以关键字删除");
    puts("5>以关键词字6>以项数查找");
    puts("7>以关键字查找8>查看全部数据");
    puts("9>ESC");
    scanf("你的选择:%d\n",&choice);
//函数数组！！！
}