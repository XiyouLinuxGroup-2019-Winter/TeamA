/*************************************************************************
	> File Name: linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 21时38分56秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* create()
{
    Node* head=(Node*)malloc(Node);
    head->next=NULL;
    return head;
}

Node* AddEnd(Node* head)
{
    Node* pnew=head;
    while(pnew->next!=NULL)
        pnew=pnew->next;
    while(1)
    {
        printf("请输入数字:");
        scanf("%d",&data);
        
        while(data==-1)
            return head;
        Node* p=(Node*)malloc(Node);
        pnew->next=p;

        pnew->data=data; 
        p->next=NULL;
    }
    return head;
}

Node* AddFirst(Node* head)
{

    int data;
    while(1)
    {
        printf("请输入数字:");
        scanf("%d",&data);
        if(data==-1)
            return head;
        Node* p=(Node*)malloc(Node);
        p->next=head;

        head=p;
        p->data=data;

    }
}

Node* Delete_i(Node* head,int i)
{
    int cnt=1;
    Node* t=head;
    Node* t_1=NULL;

    if(t->cnt<i)
    {
        printf("没有这个结点:");
        return head;
    }
    t_1->next=t->next;
    free(t);

    head->cnt--;
    return head;
}
Node *Delete_key(Node* head,int key)
{
    Node *t,*t_1;
    t=t_1=head;

    while(t->next!=NULL)
    {
        if(t->data==key)
        {
            t_1->next=t->next;
            free(t);
        }
        t_1=t;
        t=t->next;
    }
    return head;
}
