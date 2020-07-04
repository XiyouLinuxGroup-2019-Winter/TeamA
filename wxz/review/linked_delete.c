/*************************************************************************
	> File Name: linked_delete.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月24日 星期一 15时09分09秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;
Node* men(int n);
void print(Node* head);
void delete(Node* head,int n);

int main()
{
    int n;
    Node* head;
    head=(Node*)malloc(sizeof(Node));
    scanf("%d",&n);
    head=men(n);
    printf("%d\n",n);
    print(head);
    delete(head,n);
}
Node* men(int n)
{
    int i;
    Node* head,*p;
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->data);
        p->next=head->next;
        head->next=p;
    }
    return head;
}
void print(Node* head)
{
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    p=head->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
void delete(Node* head,int n)
{
    int a=0;
    Node* p,*q,*t;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        t=p;
        q=p->next;
        while(q!=NULL)
        {
            if(p->data==q->data)
            {
                a++;
                t->next=q->next;
                free(q);
                q=t->next;
                continue;
            }
            t=q;
            q=t->next;
        }
    }
    printf("%d",n-a);
    print(head);
}

