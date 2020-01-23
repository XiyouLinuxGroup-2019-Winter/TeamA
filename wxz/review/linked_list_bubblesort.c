/*************************************************************************
	> File Name: linked_list_bubblesort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月22日 星期三 22时12分26秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
}Node;

void Create();
void print();
void BubbleSort(Node* head);
int main()
{
    struct NODE Node[5]={1,2,5,3,8};
    BubbleSort(Node);
    int i;
    Node *head
    for()
}
void BubbleSort(Node* head)
{
    Node *p,*q;
    for(p->next;p!=NULL;p=p->next)
    {
        for(q->next;q!=NULL;q=q->next)
        {
            if((p->data)>(q->data))
            {
                int t=p->data;
                p->data=q->data;
                q->data=t;
            }
        }
    }
}
void print()
{
    
}
