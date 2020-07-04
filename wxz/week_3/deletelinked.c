/*************************************************************************
	> File Name: deletelinked.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月31日 星期五 23时16分28秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
struct ListNode{
    int data;
    struct ListNode* next;
};
struct ListNode* readlist();
struct ListNode* deletem(struct ListNode*L,int m);
void printlist(struct ListNode* L);
int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}
void printlist(struct ListNode *L)
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}
struct ListNode *readlist()
{
	int num;
	struct ListNode *head,*p;
	head=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=head;
	while(scanf("%d",&num )!=EOF&&num!=-1)
	{
		p->next =(struct ListNode*)malloc(sizeof(struct ListNode));
		p=p->next ;
		p->data =num;
		p->next=NULL;
	}
	head=head->next ;

	return (head);
}
/*struct ListNode* readlist()
{
    struct ListNode* head,*p;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=head;
    int data;
    while(1)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&data);
        p=p->next;
        p->data=data;
        if(data==-1)
            break;
        p->next=NULL;
    }
    head->next=head;
    return head;
}*/
struct ListNode* deletem(struct ListNode*L,int m)
{
    struct ListNode* q,*p;
    if(L==NULL)
        return NULL;
    p=L;
    q=p->next;
    while(q)
    {
        if(q->data==m)
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else{
            p=p->next;
            q=p->next;
        }
    }
    if(L->data==m)
        L=L->next;
    return L;
}
