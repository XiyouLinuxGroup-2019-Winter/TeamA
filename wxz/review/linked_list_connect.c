/*************************************************************************
	> File Name: linked_list_connect.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月22日 星期三 22时48分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct list{
    int data;
    struct list* next;
}Node;

Node *delete_node(Node* p,Node* t);
void selection_sort(Node* p,int n);
Node* Create(int a[],int n);
Node* concate(Node* p1,Node *p2);


int main()
{
    int a[]={3,12,8,9,11};
    Node* p;
    p=Create(a,5);
    selection_sort(p,5);
}
Node *delete_node(Node* p,Node* t)
{
    if(t==NULL)//删除头结点
        return p->next;
    else
    {
        if(t->next->next==NULL)//删除尾结点
            t->next=NULL;
        else //删除其他结点
                t->next=t->next->next;
            return p;
    }
}
void selection_sort(Node* p,int n)
{
    Node *t,*tmp;
    int i,min;
    for(i=0;i<n;i++)
    {
        tmp=p;
        min=t->data;
        tmp=NULL;
        while(t->next)
        {
            if(min>(t->next->data))
            {
                min=t->next->data;
                tmp=t;
            }
            t=t->next;
        }
        printf("%d",min);
        p=delete_node(p,tmp);

    }
}
Node* Create(int a[],int n)
{
    Node *t1,*t2,*p;
    p=(Node*)malloc(sizeof(Node));
    p->data=a[0];
    t1=p;
    int i;
    for(i=1;i<n;i++)
    {
        t2=(Node*)malloc(sizeof(Node));
        t2->next=NULL;
        t2->data=a[i];
        t1->next=t2;
        t1=t1->next;
    }
    return p;
}
Node* concate(Node *p1,Node* p2)
{
    Node *t;
    t=p1;
    while(t->next)
        t=t->next;
    t->next=p2;
    return p1;
}

