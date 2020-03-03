/*************************************************************************
	> File Name: linked_delete_data.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月24日 星期一 20时55分46秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* delete(Node* head,int n);
Node* input();
int main()
{
    Node* p;
    p=input();
    int n;
    scanf("%d",&n);
    delete(p,n);
    while(p)
    {
        p=p->next;
        printf("%d",p->data);
    }
}
Node* input()
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
Node* delete(Node* head,int n)
{
    Node* p;
    p=head;
    Node* t;
    while(p!=NULL)
    {
        if(p->data==n)
        {
            p=p->next;
            t->next=p->next;
        }
        free(p);
    }
}
