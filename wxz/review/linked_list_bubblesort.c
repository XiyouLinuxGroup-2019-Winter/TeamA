/*************************************************************************
	> File Name: linked_list_bubblesort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月22日 星期三 22时12分26秒
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
    Node *p=NULL,*tail=NULL;
    p=head;
    while(p!=tail)
    {
        while(p->next!=tail)
        {
            if((p->data) > (p->next->data))
            {
                int t=p->data;
                p->data=p->next->data;
                p->next->data=t;
            }
            p=p->next;
        }
        tail=p;
        p=head;
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

