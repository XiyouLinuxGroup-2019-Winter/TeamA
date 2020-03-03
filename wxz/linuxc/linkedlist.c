/*************************************************************************
	> File Name: linkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 03时17分07秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
static Node* head=NULL;
Node* create(int data)
{
    //int data;
    //scanf("%d",&data);
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=NULL;
    return p;
}
void Free(Node* p)
{
    free(p);
}
Node* search(int key)
{
    Node* p;
    for(p=head;p;p=p->next)
    {
        if(p->data==key)
            return p;
        else
            return NULL;
    }
}
void insert(Node* p)
{
    p->next=head;
    head=p;
}
void delete(Node* p)
{
    Node* pre;
    if(p==head)
    {
        head=p->next;
        return ;
    }
    for(pre=head;pre;pre=pre->next)
    {
        if(pre->next==p)
        {
            pre->next=p->next;
            return ;
        }
    }
}
void traverse(void (*visit)(Node*))
{
    Node* p;
    for(p=head;p;p=p->next)
        visit(p);
}
void destory()
{
    Node* q,*p=head;
    head=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
}
void push(Node* p)
{
    insert(p);
}
Node* pop()
{
    if(head==NULL)
        return NULL;
    else{
        Node* p=head;
        head=head->next;
        return p;
    }
}
