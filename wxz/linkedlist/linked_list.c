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
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->n=0;
    return head;
}

Node* AddEnd(Node* head)
{
    int data;
    Node* pnew=head;
    while(pnew->next!=NULL)
        pnew=pnew->next;
    while(1)
    {
        printf("请输入数字:");
        scanf("%d",&data);
        
        if(data==-1)
            return head;
        Node* p=(Node*)malloc(sizeof(Node));
        pnew->next=p;
        pnew=p;

        pnew->next=NULL;
        pnew->data=data; 
        //pnew->next=NULL;
        head->n++;
        
    }
    return head;
}
/*Node* AddEnd(Node* head)
{
    Node* pnew,*p;
    int data;
    if(!(pnew=(Node*)malloc(sizeof(Node))))
    {
        puts("内存分配失败!\n");
        return NULL;
    }
    else
    {
        while(1)
        {
            scanf("%d",&data);
            pnew->data=data;

            pnew->next=NULL;
            if(head=NULL)
            {
                head=pnew;
                return head;
            }
            p=head;
            while(p->next!=NULL)
                p=p->next;
            p->next=pnew;
            
            pnew->next=NULL;
            head->n++;
        }
    }
    return head;
}*/


/*Node* AddFirst(Node* head)
{
    int data;
    Node* pnew=head;
    while(1)
    {
        puts("请输入数字：");
        scanf("%d",&data);
        if(data==-1)
            return head;
        Node* p=(Node*)malloc(sizeof(Node));
        p->next=pnew->next;
        pnew->next=p;
    }
    return head;
}*/
Node* AddFirst(Node* head)
{
    Node* pnew=head;
    int data;
    while(1)
    {
        printf("请输入数字:");
        scanf("%d",&data);
        if(data==-1)
            return head;
        Node* p=(Node*)malloc(sizeof(Node));
        p->next=pnew;
        pnew=p;

        p->data=data;

        p->n=head->n+1;
        head->n=0;

    }
    return head;
}

Node* Delete_i(Node* head,int i)
{
    int n=1;
    Node* t=head;
    Node* t_1=NULL;

    if(t->n<i)
    {
        printf("没有这个结点:");
        return head;
    }
    t_1->next=t->next;
    free(t);

    head->n--;
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

        head->n--;
    }
    return head;
}

Node* change(Node* head,int n,int new)
{
    Node* t=head;
    int i=0;
    while(i<n && t!=NULL)
    {
        t=t->next;
        i++;
    }
    if(t!=NULL)
        t->data=new;
    else
        puts("结点不存在！\n");
    return head;
}

Node *Find_i(Node* head,int i)
{
    int n=1;
    Node* t=head;
    while(t->next!=NULL && n<i)
    {
        t=t->next;
        n++;
    }
    if(n<i)
        puts("找不到该结点!\n");
    else
        printf("%d",t->data);
    return head;
}

Node *Find_key(Node* head,int key)
{
    Node *t=head;
    while(t->next!=NULL)
    {
        if(t->data==key)
            printf("%d ",t->data);
        t=t->next;
    }
    return head;
}

void Print()
{
    Node *head,*t;
    t=head;
    while(t->next!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    putchar('\n');
}


