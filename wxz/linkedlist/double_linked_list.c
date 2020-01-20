/*************************************************************************
	> File Name: double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月20日 星期一 12时18分45秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

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

        p->next=pnew->next;
        p->pre=pnew;
        if(pnew->next!=NULL)
        pnew->next->pre=p;
        pnew->next=p;

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
    
}






