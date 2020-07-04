/*************************************************************************
	> File Name: palin_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月24日 星期一 07时55分32秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    struct NODE* next;
    int data;
}Node;
Node* input();
int length(Node* head);
Node* late(Node* head,int n);
int compare(Node* p1,Node* p2,int n);


int main()
{
    int n,x;
    Node* p,*q;
    p=input();
    n=length(p);
    q=late(p,n);
    x=compare(p,q,n);
    if(x==1)
        printf("回文链表");
    else
    printf("不是回文链表");
}


Node* input()
{
    int data;
    Node* head=NULL;
    Node* tail=NULL;
    scanf("%d",&data);
    while(data!=-1)
    {
        Node* p=(Node*)malloc(sizeof(Node));
        p->data=data;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->next=p;
            tail=p;
        }
        scanf("%d",&data);
    }
    return head;
}
int length(Node* head)
{
    int i=0;
    Node* p=head;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
Node* late(Node* head,int n)
{
    int x;
    int i=1;
    Node* p=head;
    Node* a,*b,*c;
    if(n%2==0)
        x=(n/2)+1;
    else
        x=(n/2)+2;
    while(i!=x)
    {
        p=p->next;
        i++;
    }
    a=p;
    b=a->next;
    c=b;
    a->next=NULL;
    while(b!=NULL)
    {
        c=c->next;
        b->next=a;
        a=b;
        b=c;
    }
    return a;
}
int compare(Node* p1,Node* p2,int n)
{
    int flag=1;
    while(p2)
    {
        if(p1->data!=p2->data)
        {
            flag=0;
            break;
        }
        else
        {
            p1=p1->next;
            p2=p2->next;
        }
    }
    return flag;
}
