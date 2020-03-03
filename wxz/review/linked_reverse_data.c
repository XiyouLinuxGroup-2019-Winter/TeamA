/*************************************************************************
	> File Name: linked_reverse_data.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月23日 星期日 23时32分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* input();
Node* reverse(Node* head);
int main()
{
    int i=1;
    int n;
    Node* p;
    p=input();
    scanf("%d",&n);
    getchar();
    p=reverse(p);
    while(p!=NULL)
    {
        if(i==n)
            printf("%d",p->data);
        i++;
        p=p->next;
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
/*Node* reverse(Node* head)
{
    Node*t,*p,*r;
    p=head;
    while(p)
    {
        t=p->next;
        p->next=r;
        r=p;
        p=t;
    }
    return r;
}*/
/*Node* reverse(Node* head)
{
    Node* a,*b,*c;
    a=head;
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
}*/
Node* reverse(Node* head)
{
    Node* pnew,*pend;
    pnew=head->next;
    head->next=NULL;
    while(pnew)
    {
        pend=pnew;
        pnew=pnew->next;
        pend->next=head->next;
        head->next=pend;
    }
    return head;
}
