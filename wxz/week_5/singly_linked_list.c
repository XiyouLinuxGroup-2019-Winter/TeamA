/*************************************************************************
	> File Name: singly_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月19日 星期三 02时39分19秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"
Node* Find(Node* head)
{
    int data;
    Node* p;
    printf("请输入数字：");
    scanf("%d",&data);
    for(p=head;p->next;p=p->next)
    {
        if(p->next->data==data)
        {
            printf("%d\n",p->next->data);
            break;

        }

    }
    if(p->next==NULL)
        puts("不存在此结点\n");
    return head;
}

void Print(Node* head)
{
    Node* p;
    for(p=head->next;p;p=p->next)
        printf("%d\n",p->data);
}
int Ruin(Node* head)
{
    Node* p=NULL;
    int choice;
    printf("确定销毁？（１：销毁　２．不销毁）\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        for(p;head->next;)
        {
            p=head->next;
            head->next=p->next;
            free(p);
        }
        free(head);
        printf("销毁成功\n");
    }
    if(choice==2)
        return 0;
}
Node* Delete(Node* head)
{
    Node* p;
    p=head->next;
    head->next=p->next;
    free(p);
    printf("删除成功\n");
}
void Add(Node* head)
{
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    printf("请输入数字\n");
    scanf("%d",&p->data);
    p->next=head->next;
    head->next=p;
}
Node* Input(Node* head)
{
    char choice;
    Node* p;
    Node* q;
    head=(Node*)malloc(sizeof(Node));
    q=head;
    do{
        p=(Node*)malloc(sizeof(Node));
        printf("请输入数字\n");
        scanf("%d",&p->data);
        p->next=NULL;
        head->next=p;
        head=p;
        printf("继续＞(Y/N)\n");
        getchar();
        scanf("%c",&choice);
    }while(choice=='Y' || choice=='y');
    return q;
}
