/*************************************************************************
	> File Name: circular_double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月23日 星期四 23时07分25秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
Node* Create()
{
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->n=0;
    return head;
}

Node* AddFirst(Node* head)
{
    Node* pnew;
    int data;
    pnew=head;
    while(1)
    {
        puts("请输入:");
        scanf("%d",&data);

        if(data==-1)
            break;
            Node* p=(Node*)malloc(sizeof(Node));
            if(p==NULL)
            {
                p->data=data;
                p->next=pnew;
                pnew->next=p;
            }
    }
    return head;
}
Node* AddEnd(Node* head)
{
    Node* pnew=head;
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

        p->next=pnew;
        pnew->next=head;
    }
    return head;
        
}

Node* Delete_i(Node* head,int i)
{
    int j=1;
    Node* pnew=head;
    while(pnew->next!=head && j<i)
    {
        pnew=pnew->next;
        j++;
    }
    if(j==i && pnew->next != head)
    {
        Node* t=pnew->next;
        pnew->next=t->next;
        free(t);
    }
    return head;
}
void Print(Node* head)
{
    Node* pnew=NULL;
    for(pnew=head->next;pnew!=head;pnew=pnew->pnew)
        printf("%d ",pnew->data);
    putchar('\n');
    return head;
}

int Find_key(Node* head,int key)
{
    Node* pnew=NULL;
    int j=0;
    int index=-1;
    for(pnew=head->next;pnew!=head;pnew=pnew->next)
    {
        j++;
        if(pnew->data==key)
            index=j;
    }
    if(j==-1)
        puts("该结点不存在");
    else
        printf("该结点在第%d个位置\n",index);
    return index;
}
int Find_i(Node* head,int i)
{
    if(head==NULL || i<1)
        return NULL;
    Node* pnew=NULL;
    int j=0;
    int data=-1;
    for(pnew=head->next;pnew!=head;pnew=pnew->next)
	{
		j++;
		if(j==i)
		{
			data=pnew->data;
		}
	}
	if (i>j)
	{
		printf("第%d个位置结点不存在\n",i);
	}
	else
	{
		printf("第%d个位置的数据:%d\n",i,data);
	}
	return data;
}
