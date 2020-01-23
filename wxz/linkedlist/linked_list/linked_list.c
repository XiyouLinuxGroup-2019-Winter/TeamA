/*************************************************************************
	> File Name: linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月22日 星期三 23时46分03秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "linked_list.h"
Node* Create(Node* head)
{
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->n=0;
    return head;
}
Node* AddFirst(Node* head)
{
    int data;
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            return head;
        Node* pnew=(Node*)malloc(sizeof(Node));
        pnew->data=data;

        pnew->next=head->next;
        head->next=pnew;

        head->n++;
    }
    return head;
}
Node* AddEnd(Node* head)
{
    int data;
    Node* pnew,*tail;
    tail=head;
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            return head;
        pnew=(Node*)malloc(sizeof(Node));
        pnew->next=tail->next;
        tail->next=pnew;
        tail=pnew;

        head->n++;
    }
    return head;

}

Node* Find_i(Node* head,int i)
{
    Node* pnew;
    int j=1;
    pnew=head->next;
    while(j<i && pnew!=NULL)
    {
        pnew=pnew->next;
        j++;
    }
    if(j>i || pnew==NULL)
        puts("找不到这个结点");
    else
        return (pnew->next);
}
Node* Find_key(Node* head,int key)
{
    Node* pnew=head->next;
    while(pnew!=NULL && pnew->data!=key)
        pnew=pnew->next;
    if(pnew->data==key)
        return pnew;
    else
    {
        puts("这个结点不存在");
        return NULL;
    }
}

Node* change(Node* head,int n,int new)
{
    Node* t=head->next;
    int j=1;
    while(t!=NULL && j<n)
    {
        t=t->next;
        j++;
    }
    if(t!=NULL)
        t->data=new;
    else
        puts("结点不存在");
    return head;
}

Node* Delete_i(Node* head,int i)
{
    int j=0;
    Node* p,*q;
    p=head;
    q=head->next;
    while(p->next!=NULL && j<i-1)
    {
        p=q;
        q=q->next;
        j++;
    }
    if(p->next==NULL || j>i-1)
        puts("该结点不存在!");
    else
    {
        p->next=q->next;
        free(q);
        head->n--;
    }
    return head;
}

Node* Delete_key(Node* head,int key)
{
    Node* p,*q;
    p=head;
    q=head->next;
    while(q!=NULL && q->data!=key)
    {
        p=q;
        q=q->next;
    }
    if(q->data==key)
    {
        p->next=q->next;
        free(q);
        head->n--;
    }
    else
        printf("要删除的结点不存在");

    return head;
}

void Print()
{
    Node* head;
    Node* t=head;
    while(t->next !=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    putchar('\n');
}
