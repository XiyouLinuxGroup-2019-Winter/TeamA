/*************************************************************************
	> File Name: linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月20日 星期四 16时04分56秒
 ************************************************************************/

#include<stdio.h>
#include "linked_list.h"
#include<stdlib.h>
Node* Create()
{
    Node* head=NULL;
    Node* end,*new;
    end=new=(Node*)malloc(sizeof(Node));
    n=0;
    int data;
    printf("请输入数据\n");
    scanf("%d",&new->data);
    while(new->data!=0)
    {
        n++;
        if(n==1)
        {
            new->next=NULL;
            end=new;
            head=new;
        }
        else
        {
            new->next=NULL;
            end->next=new;
            end=new;
        }
        new=(Node*)malloc(sizeof(Node));
        scanf("%d",&new->data);
    }
    free(new);
    return head;
}
void Print(Node* head)
{
    Node* t;
    int i=1;
    t=head;
    while(t!=NULL)
    {
        t=t->next;
        i++;
    }
}
Node* Add(Node* head)
{
    Node* new;
    new=(Node*)malloc(sizeof(Node));
    scanf("%d",&new->data);
    new->next=head;
    head=new;
    n++;
    return head;
}
void Delete(Node* head,int i)
{
    int index;
    Node* t;
    Node* pre;
    t=head;
    pre=t;
    for(index=1;i;)
    {
        
    }
}
