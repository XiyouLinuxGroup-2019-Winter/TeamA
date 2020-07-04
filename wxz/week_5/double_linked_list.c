/*************************************************************************
	> File Name: double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月19日 星期三 15时09分31秒
 ************************************************************************/

#include<stdio.h>
#include "double_linked_list.h"
#include <stdlib.h>
void Create(Node* head)
{
    Node* p;
    Node* rear=head;
    int data;
    while(scanf("%d",&data),data!=-1)
    {
        p=(Node*)malloc(sizeof(Node));
        p->data=data;

        rear->next=p;
        p->pro=rear;
        rear=p;
    }
    rear->next=NULL;
}
void Print(Node* head)
{
    Node* p=head->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void Delete(Node* head,int i)
{
    Node* p=head;
    int j=1;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || i<i)
    return ;
    p->next=p->next->next;
    p->next->next->pro=p;
}
void Add(Node* head,int i,int data)
{
    int data;
    Node* p=head;
    Node* t;
    int j=1;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || i<1)
        return ;
    t=(Node*)malloc(sizeof(Node));
    t->data=data;
    t->next=p->next;
    p->next->pro=t;
    p->next=t;
    t->pro=p;
}
void reverse(Node* head)
{
    Node* p=head->next;
    int j=1;
    while(p && j<=n-1)
    {
        j++;
        p=p->next;
    }
    printf("%d ",p->data);
    while(p && j>1)
    {
        printf(" %d",p->pro->data);
        p=p->pro;
        j--;
    }
}
