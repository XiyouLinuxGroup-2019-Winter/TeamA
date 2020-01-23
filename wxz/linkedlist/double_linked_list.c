[/*************************************************************************
	> File Name: double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月20日 星期一 12时18分45秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* Create()
{
    Node* head;
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->pre=NULL;

    head->n=0;
    return head;
}

Node* AddFirst(Node* head)
{
    Node* pnew=head;
    int data;
    while(1)
    {
        puts("请输入：");
        scanf("%d",&data);
        
        if(data==-1)
            break;
        Node* p=(Node*)mallco(sizeof(Node));
        p->data=data;

        p->next=NULL;
        while(pnew->next!=NULL)
            pnew=pnew->next;
        pnew->next=p;
        p->pre=pnew;

        head->n++;
    }
    return head;
}


Node* AddEnd(Node* head)
{
    Node *pnew=head;
    int data;
    while(pnew->next!=NULL)
        pnew=pnew->next;
    while(1)
    {
        puts("请输入:");
        scanf("%d",&data);
        if(data==-1)
            break;

        Node* p=(Node*)malloc(sizeof(Node));
        p->data=data;

        p->next=NULL;
        p->pre=pnew;
        pnew->next=p;
        pnew=pnew->next;

        head->n++;
    }
    return head;
}

Node* Delete_i(Node* head,int i)
{
    Node*pnew=head;
    if()
}
Node *Delete_key(Node* head,int key)
{
    Node* pnew=head;
    while(pnew->data != key)
        pnew=pnew->next;
    pnew->pre->next=pnew->next;
    pnew->next->pre=pnew->pre;

    head->n--;
    return head;
}
void change(Node* head,int n,int new)
{
	Node* pnew=head;
	int j=1;
	while(j!=n)
	{
		pnew=pnew->next;
		j++;
	}
    pnew->data=new;
}

Node* Find_key(Node* head,int key)
{
    Node* pnew=head;
    int j=1;
    while(j!=key)
    {
        pnew=pnew->next;
        j++;
    }
    printf(" %d \n",pnew->data);
}





