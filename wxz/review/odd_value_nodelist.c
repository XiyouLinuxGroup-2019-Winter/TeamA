/*************************************************************************
	> File Name: odd_value_nodelist.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 09时06分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};


struct ListNode *readlist();
struct ListNode *getodd(struct ListNode **L );
void printlist(struct ListNode *L )
{
     struct ListNode *p = L;
     while(p) 
    {
           printf("%d ",p->data);
           p=p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L,*Odd;
    L=readlist();
    Odd=getodd(&L);
    printlist(Odd);
    printlist(L);


}
/*struct ListNode* readlist()
{
    struct ListNode* p,*head,*tail;
    p=(struct ListNode*)malloc(sizeof(struct ListNode));
    while(tail && head)
    {
        head=p;
        scanf("%d",&p->data);
        p=p->next;
        if(p->data==-1)
            break;
        tail=NULL;
    }
    free(p);
    return head;
}
struct ListNode* getodd(struct ListNode**L)
{
    struct ListNode *head,*tail,*head1,*tail1;
    int i;
    while(head && tail && head1 && tail1)
    {
        i=(*L)->data;
        if(i%2!=0)
        {
            head=*L;
            *L=(*L)->next;
            tail=NULL;
        }
        if(i%2==0)
        {
            head1=*L;
            *L=(*L)->next;
            tail1=NULL;
        }
    }
    return head,head1;
}*/

struct ListNode *readlist()
{
    struct ListNode* head,*tail,*p;
    p=(struct ListNode*)malloc(struct ListNode);
    head=NULL;
    tail=NULL;
    while(1)
    {
        p->next=NULL;
        scanf("%d",&p->data);
        if(head==NULL)
            head=p;
        else
            tail->next=p;
        tail=p;
        if(p->data==-1)
        break;
    }
    return head;
}
struct ListNode *getodd(struct ListNode **L )
{
    struct ListNode *head,head1,tail,tail1;
   
    int i;
    while(1)
    {
        i=(*L)->data;
        if(i%2!=0)
        {
            if(head==NULL)
                head=(*L);
            else
                tail->next=(*L);
            tail=(*L);
        }
        if(i%2==0)
        {
            if(head1==NULL)
                head1=*L;
            else
                tail1->next=*L;
            tail1=(*L);
        }
        *L=(*L)->next;
    }
    
    return head1,head;
    
}
