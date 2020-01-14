#include<stdio.h>
#define MAXSIZE 11
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct 
{
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

int ListLength(StaticLinkList L);
Status InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);
Status ListInsert (StaticLinkList L,int i,ElemType e);
void Free_SSL(StaticLinkList space,int k);
Status ListDelete(StaticLinkList L,int i);

Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
        space[i].data=0;
    }
    space[MAXSIZE - 1].cur = 0;
    return OK;
}
int Malloc_SLL(StaticLinkList space)   
{
    int i=space[0].cur;
    if(space[0].cur)
    space[0].cur=space[i].cur;
    return i;
}
Status ListInsert (StaticLinkList L,int i,ElemType e)
{
    int j,k,l;
    k=MAXSIZE-1;
    if (i<1||i>ListLength(L)+1)
    {
        return ERROR;
    }
    j=Malloc_SLL(L);
    if (j)
    {
        L[j].data=e;
        for ( l = 1; l <= i-1 ; l++)
        {
            k=L[k].cur;//k->i-1
        }
        L[j].cur=L[k].cur;//j的下一个是原来的i
        L[k].cur=j;//j变为第i个
        return OK;
        
    }
    return ERROR;
}
Status ListDelete(StaticLinkList L,int i)
{
    int j,k;
    if (i<1||i>ListLength(L))
    {
        return  ERROR;
    }
    k=MAXSIZE-1;
    for ( j =1; j <=i-1; j++)
    {
        k=L[k].cur;//k->第i-1个节点,注意到到k是MAXSIZE-1开始
    }
    j=L[k].cur;//j->第i
    L[k].cur=L[j].cur;//i-1的cur-->i+1
    printf("删除了%d\n",j);
    Free_SSL(L,j);
    return OK;    
}

void Free_SSL(StaticLinkList space,int k)
{
    space[k].cur=space[0].cur;//表明k的下一个节点指向链表此时第一个空节点
    space[0].cur=k;//k变成第一个空节点
    
}

int ListLength(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while (i)
    {
        i=L[i].cur;
        j++;
    }
    return j;   
}