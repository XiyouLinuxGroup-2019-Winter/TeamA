/*************************************************************************
	> File Name: double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 16时54分14秒
 ************************************************************************/

#include<stdio.h>
#include "double_linked_list.h"
#include <stdlib.h>
Node* Create()
{
    Node* p,*q,*pnew;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("错误!\n");
        return NULL;
    }
    p->next=NULL;
    p->pre=NULL;
    p->n=0;
    q=p;
    while(1)
    {
        pnew=(Node*)malloc(sizeof(Node));
        printf("请输入值:\n");
        scanf("%d",&pnew->data);
        if(pnew->data==-1)
            break;
        q->next=pnew;
        pnew->pre=q;
        pnew->next=NULL;
        q=pnew;
    }
    q->next=p;
    p->pre=q;

    p->n++;
    return p;
}
void Print(Node* p)
{
    Node* temp;
    temp=p->next;
    while(temp!=p)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void Print1(Node* p)
{
    Node* temp;
    temp=p->pre;
    while(temp!=p)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void Destory(Node* p)
{
    Node *temp;
    Node* pre;
    temp=p->next;
    while(temp!=p)
    {
        pre=temp;
        temp=temp->next;
        free(pre);
    }
    free(p);
}
void Insert(Node* p)
{
    Node* temp,*pnew,*pro,*pre1,pre2;
    temp=p;
    pnew=(Node*)malloc(sizeof(Node));
    printf("请输入数字\n");
    scanf("%d",&pnew->data);
    pro=p;
    int data;
    printf("请输入要插入的位置号码:\n");
    scanf("%d",&data);
    int flag=0;
    while(1)
    {
        temp=temp->next;
        pro=pro->pre;
        if(temp->data==data)
        {
            pnew->next=temp;
            temp->pre->next=pnew;
            pnew->pre=temp->pre;
            temp->pre=pnew;
            break;
        }

        if(pro->data==data)
        {
            pnew->pre=pro;
            pro->next->pre=pnew;
            pnew->next=pro->next;
            pro->next=pnew;
            break;
        }
        if(pro==temp)
        {
            printf("不存在！\n");
            return ;
        }
    }
    printf("插入完成！\n");
}
void Delete(Node* p)
{
    Node* temp,*pro;
    temp=p;
    int data;
    scanf("%d",&data);
    while(1)
    {
        temp=temp->next;
        pro=temp->pre;
        if(temp->data==data)
        {
            temp->pre->next=temp->next;
            temp->next->pre=temp->pre;
            free(temp);
            break;
        }
        if(pro->data==data)
        {
            pro->next->pre=pro->pre;
            pro->pre->next=pro->next;
            free(pro);
            break;
        }
        if(temp==pro)
        {
            printf("不存在！\n");
            return ;
        }
    }
    printf("删除成功！\n");
}

