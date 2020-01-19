/*************************************************************************
	> File Name: circular_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 13时15分49秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    struct NODE* next;
    int data;
}Node;

int cnt=0;
Node* create(Node* head);
void print(Node* head);
int main()
{
    Node* head=NULL;
    create(head);
    

}

Node* create(Node* head)
{
    Node* end;
    Node* pnew;
    int n,i;
    printf("创建几个结点:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        pnew=(Node*)malloc(sizeof(Node));
        printf("请输入值:");
        scanf("%d",&pnew->data);
        pnew->next=NULL;
        if(head=NULL)
            head=pnew;
        else
            end->next=pnew;
        end=pnew;
        cnt++;
    }
    end->next=head;
    return head;
}
void print(Node* head)
{
    Node* t=head;

    while(t->pre)
}


