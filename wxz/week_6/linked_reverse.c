/*************************************************************************
	> File Name: linked_reverse.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 00时12分49秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* input();
Node* reverse(Node* head);//就地逆置
void head_invert(Node* head);
Node* inver(Node* head);
Node* create_1();
Node* create();
void print(Node* head);
int main()
{
    Node* p;
    //p=create();
    //reverse(p);
    p=create_1();
    //print(p);
    p=reverse(p);
    //head_invert(p);
   // p=inver(p);
   print(p);
}
void print(Node* head)
{
    Node* t;
    t=head->next;
    while(t)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}
void head_invert(Node* head)
{
    Node* p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        q->next=head->next;
        head->next=q;
    }
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
Node* reverse(Node* head)
{
    /*Node* tail,*middle;
    middle=NULL;
    while(head)
    {
        tail=middle;
        middle=head;
        head=head->next;
        middle->next=tail;
    }*/
    Node* p,*q,*t;
    p=head;
    q=NULL;
    while(p!=NULL)
    {
        t=p;
        p=p->next;
        t->next=q;
        q=t;
    }
    return q;
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
Node* create()
{
    int data;
    Node* head=(Node*)malloc(sizeof(Node));
    Node* tail;
    tail=head;
    //tail->next=NULL;
    while(tail->next!=NULL)
        tail=tail->next;
    while(1)
    {
        scanf("%d",data);
        if(data==-1)
            break;
        Node* new=(Node*)malloc(sizeof(Node));
        new->data=data;
        new->next=tail->next;
        tail->next=new;
        tail=new;
        //tail->next=new;
        //new->next=NULL;
        //tail=tail->next;
    }
    return head;
}

Node* create_1()
{
    int data;
    Node* new,*tail;
    Node* head;
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    tail=head;
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            break;
        new=(Node*)malloc(sizeof(Node));
        new->data=data;
        //pnew->next=tail->next;
        tail->next=new;
        tail=new;
    }
    tail->next=NULL;
    return head;

}
Node* inver(Node* head)
{
    Node* t;
    if(head==NULL || head->next==NULL)
        return head;
    t=inver(head->next);
    head->next->next=head;
    head->next=NULL;
    return t;
}
/*int main()
{
    Node* head,*p1,*q1;
    int i,n;
    head=(Node*)malloc(sizeof(Node));
    if(head==NULL)
        exit(1);

    head->next=NULL;
    p1=head;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        q1=(Node*)malloc(sizeof(Node));
        if(q1==NULL)
            exit(1);
        scanf("%d",&q1->data);
        q1->next=NULL;
        p1->next=q1;
        p1=q1;
    }

    Node* p2,*q2,*t;
    p2=NULL;
    q2=head->next;
    while(q2!=NULL)
    {
        t=q2;
        q2=q2->next;
        t->next=p2;
        p2=t;
    }
    t=p2;
    while(t!=NULL)
    {
        printf("%d",t->data);
        t=t->next;
    }
    free(head);
    free(q1);
}*/
