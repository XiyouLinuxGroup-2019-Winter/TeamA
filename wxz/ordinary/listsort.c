/*************************************************************************
	> File Name: listsort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月16日 星期一 11时58分06秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* Create();
Node* create_1();
void print(Node* head);
Node* BubbleSort(Node* head);
Node* Reverse(Node* head);


Node* create_1()
{
    int data;
    Node* new,*tail;
    Node* head;
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    tail=head;
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            break;
        new=(Node*)malloc(sizeof(Node));
        new->data=data;
        //pnew->next=tail->next;
        tail->next=new;
        tail=new;
    }
    tail->next=NULL;
    return head;

}
Node* Reverse(Node* head)
{
    Node* p1;// 用来遍历结点一个一个截取
    Node* p2;//用来存储要指向的结点
    Node* p;//用来保存下一个要截取的结点

    p1=head;//从头结点开始
    p2=NULL;//第一个指向空指针
    while(p1!=NULL)
    {
        p=p1->next;//保存下一个结点
        p1->next=p2;//改变该结点的指向
        p2=p1;//
        p1=p;
    }
    head=p1;//头指针指向最后
    return head;
}
void print(Node* head)
{
    Node* p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
   // printf("\n");
}
Node* Create()
{
    int data;
    scanf("%d",&data);
    Node* head=NULL,*tail=NULL;
    while(data!=-1)
    {
        Node* new=(Node*)malloc(sizeof(Node));
        new->data=data;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }
        scanf("%d",&data);
    }
    return head;
}



int main()
{
    int n;
    Node* p;
    //p=Create();
    p=create_1();
    //scanf("%d",&n);
    //getchar();
    //p=BubbleSort(p);
    //print(p);
    p=Reverse(p);
    print(p);
}
