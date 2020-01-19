/*************************************************************************
	> File Name: double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 15时48分54秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    struct NODE *tre;//后趋
    struct NODE *pre;//前趋
    int data;
}Node;

int cnt=0;
Node *create(Node*head);
void print();
int main()
{
    Node *head=NULL;
    create(head);
    print();
}
Node *create(Node *head)
{
    Node *end,*pnew;
    int n,i;
    printf("创建了几个结点:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cnt++;
        pnew=(Node*)malloc(sizeof(Node));
        printf("请输入:");
        scanf("%d",&pnew->data);
        pnew->tre=NULL;
        if(head==NULL)
        {
            pnew->pre=NULL;
            head=pnew;
        }
        else
        {
            end->tre=pnew;
            pnew->pre=end;
        }
        end=pnew;
    }
    return head;
}
void print()
{
    Node* head;
    Node* t=head;
    Node* t1=head;

    //从左开始遍历
    while(t)
    {
        printf("%d\t",t->data);
        t=t->tre;
    }
    //遍历到了链表尾
    while(t1 && t1->tre!=NULL)
        t1=t1->tre;
    printf("\n");
    //从右开始遍历
    while(t1)
    {
        printf("%d\t",t1->data);
        t1=t1->pre;
    }
}
