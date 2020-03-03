/*************************************************************************
	> File Name: linke_joint.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月24日 星期一 00时46分34秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    struct NODE* next;
    int data;
}Node;
Node* input();
int main()
{
    Node* p1,*p2;
    Node* head=NULL;
    p1=input();
    p2=input();
    head=p2;
    while(p1!=NULL)
    {
        p2=head;
        while(p2!=NULL)
        {
            if(p1->data==p2->data)
                printf("%d ",p1->data);
            p2=p2->next;
        }
        p1=p1->next;
    }
}
Node* input()
{
    Node* head=NULL;
    Node* tail=NULL;
    int data;
    scanf("%d",&data);
    while(data!=-1)
    {
        Node* p=(Node*)malloc(sizeof(Node));
        p->data=data;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->next=p;
            tail=p;
        }
        scanf("%d",&data);
    }
    return head;
}

