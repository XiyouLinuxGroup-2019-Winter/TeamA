/*************************************************************************
	> File Name: linked.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月23日 星期日 23时12分06秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* Create();
int main()
{
    Node* head=NULL;
    Node* p;
    head=Create();
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
}
Node* Create()
{
    Node* head=NULL;
    Node* new=NULL;
    int data;
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            return head;
        new=(Node*)malloc(sizeof(Node));
        new->data=data;
        new->next=head;
        head=new;
    }
}
