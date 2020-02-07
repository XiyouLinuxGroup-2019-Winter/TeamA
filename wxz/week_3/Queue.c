/*************************************************************************
	> File Name: Queue.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 17时12分53秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "Queue.h"
void QueueInit(Queue* p)
{
    p->head=p->tail=NULL;
    p->n=0;
}
bool QueueIsFull(Queue* p)
{
    return p->n==max;
}
bool QueueIsEmpty(Queue* p)
{
    return p->n==0;
}
int QueueCount(Queue* p)
{
    return p->n;
}
/*bool QueueIn(int item,Queue* p)
{
    Node* pnew;
    if(QueueIsFull(p))
        return false;
    pnew=(Node*)malloc(sizeof(Node));
    if(pnew==NULL)
    {
        fprintf(stderr,"开辟内存失败!\n");
        exit(1);
    }
    CopyNode(item,pnew);
    pnew->next=NULL;
    if(QueueIsEmpty(p))
        p->head=pnew;
    else
        p->tail->next=pnew;
    p->tail=pnew;
    p->n++;
    return true;
}
static void CopyNode(int item,Node* pnew)
{
    pnew->item=item;
}
bool QueueDelete(int *pitem,Queue* p)
{
    Node* pt;
    if(QueueIsEmpty(p))
        return false;
    CopyItem(p->head,pitem);

    pt=p->head;
    p->head=p->head->next;
    free(pt);
    p->n--;
    if(p->n==0)
        p->tail=NULL;
    return true;
}
static void CopyItem(Node* pt,int* pitem)
{
    *pitem=pt->item;
}
void QueueFree(Queue* p)
{
    int dummy;
    while(!QueueIsEmpty(p))
        QueueDelete(&dummy,p);
}*/


