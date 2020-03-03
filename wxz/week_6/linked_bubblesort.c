/*************************************************************************
	> File Name: linked_bubblesort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 13时36分32秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* Create();
void print(Node* head);
Node* BubbleSort(Node* head);
int main()
{
    Node* p;
    p=Create();
    p=BubbleSort(p);
    print(p);
}
Node* BubbleSort(Node* head)
{
    Node* p;
    Node* q;
    Node* r;
    Node n;
    for(p=head;p;p=p->next)
    {
        for(q=p->next;q;q=q->next)
        {
            if(p->data>q->data)
            {
                n=*p;
                *p=*q;
                *q=n;
                r=p->next;
                p->next=q->next;
                q->next=r;
            }
        }
    }
    return head;
}
void print(Node* head)
{
    Node* p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
Node* Create()
{
    int data;
    scanf("%d",&data);
    Node* head=NULL,*tail=NULL;
    while(data!=-1)
    {
        Node* new=(Node*)malloc(sizeof(Node));
        new->data=data;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }
        scanf("%d",&data);
    }
    return head;
}
