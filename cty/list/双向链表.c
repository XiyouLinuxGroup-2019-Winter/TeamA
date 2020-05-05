#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct DoubleLinkNode
{
   int data;
   struct DoubleLinkNode *prev;
   struct DoubleLinkNode *next;
}Node;


Node*Create_Double_link()
{
   Node*head;
   Node*pnext;
   Node*plast;
   int i,n;
   head=(Node*)malloc(sizeof(Node));
   assert(NULL != head);
   head->prev=NULL;
   head->next=NULL;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct DoubleLinkNode
{
   int data;
   struct DoubleLinkNode *prev;
   struct DoubleLinkNode *next;
}Node;
Node*Create_Double_link()
{
   Node*head;
   Node*pnext;
   Node*plast;
   int i,n;
   head=(Node*)malloc(sizeof(Node));
   assert(NULL != head);
   head->prev=NULL;
   head->next=NULL;
 
   printf("please input the length of the double linked list:");
   scanf("%d",&n);
   while(n!=0)
   {
      plast=head;
      for(i=0;i<n;i++)
      {
         pnext=(Node*)malloc(sizeof(Node));
         printf("向第%d个节点输入数据:",i+1);
         scanf("%d",&pnext->data);
         plast->next=pnext;
         pnext->prev=plast;
         plast=plast->next;
      }
      pnext->next=NULL;
      break;
   }
   return head;
}
void print(Node*head)
{
  Node*temp;
  int j=0;
  temp=head;
  while(temp->next!=NULL)
  {
     j++;
     printf("输出第%d个节点的数据:%d\n",j,temp->next->data);
     temp=temp->next;
  }
  printf("输出第%d个节点的数据:%p\n",j+1,temp->next);
}
int InsertNode(Node* head)
{
   Node*new;
   Node*pnext=head;
   int i=0;
   int n;
 
   printf("please input the location which is inserted:");
   scanf("%d",&n);
 
   while((i<n) && (pnext!=NULL))
   {
      i++;
      pnext=pnext->next;
 
   }
   if(pnext==NULL)
   {
     return 1;
   }
   else
   {
        new=(Node*)malloc(sizeof(Node));
        printf("请在新插入的节点中输入数据:");
        scanf("%d",&new->data);
 
        new->next=pnext->next;
        if(n=0)
        {
          pnext->next=new;
          new->next=NULL;
        }
        else
        {
          pnext->next=new;
          pnext->next->prev=new;
          new->prev=pnext;
        }
   }
   return 0;
}
int DeleteNode(Node*head)
{
   Node*pnext=head;
   Node*ptr;
   int n;
   int i=0;
   printf("please input the node that you will delete:");
   scanf("%d",&n);
   while((i<n-1) && (pnext!=NULL))
   {
      i++;
      pnext=pnext->next;
   }
   if(pnext->next->next!=NULL)
   {
       ptr=pnext->next;
       ptr->next->prev=pnext;
       pnext=ptr->next;
       free(ptr);
   }
   else
   {
     ptr=pnext->next;
     free(ptr);
   }
  return 0;
}
int main(int argc,char**argv)
{
   Node* head;
   head=Create_Double_link();
   InsertNode(head);
   DeleteNode(head);
   print(head);
   return 0;
} 
   printf("please input the length of the double linked list:");
   scanf("%d",&n);
   while(n!=0)
   {
      plast=head;
      for(i=0;i<n;i++)
      {
         pnext=(Node*)malloc(sizeof(Node));
         printf("向第%d个节点输入数据:",i+1);
         scanf("%d",&pnext->data);
         plast->next=pnext;
         pnext->prev=plast;
         plast=plast->next;
      }
      pnext->next=NULL;
      break;
   }
   return head;
}
void print(Node*head)
{
  Node*temp;
  int j=0;
  temp=head;
  while(temp->next!=NULL)
  {
     j++;
     printf("输出第%d个节点的数据:%d\n",j,temp->next->data);
     temp=temp->next;
  }
  printf("输出第%d个节点的数据:%p\n",j+1,temp->next);
}
int InsertNode(Node* head)
{
   Node*new;
   Node*pnext=head;
   int i=0;
   int n;
 
   printf("please input the location which is inserted:");
   scanf("%d",&n);
 
   while((i<n) && (pnext!=NULL))
   {
      i++;
      pnext=pnext->next;
 
   }
   if(pnext==NULL)
   {
     return 1;
   }
   else
   {
        new=(Node*)malloc(sizeof(Node));
        printf("请在新插入的节点中输入数据:");
        scanf("%d",&new->data);
 
        new->next=pnext->next;
        if(n=0)
        {
          pnext->next=new;
          new->next=NULL;
        }
        else
        {
          pnext->next=new;
          pnext->next->prev=new;
          new->prev=pnext;
        }
   }
   return 0;
}
int DeleteNode(Node*head)
{
   Node*pnext=head;
   Node*ptr;
   int n;
   int i=0;
   printf("please input the node that you will delete:");
   scanf("%d",&n);
   while((i<n-1) && (pnext!=NULL))
   {
      i++;
      pnext=pnext->next;
   }
   if(pnext->next->next!=NULL)
   {
       ptr=pnext->next;
       ptr->next->prev=pnext;
       pnext=ptr->next;
       free(ptr);
   }
   else
   {
     ptr=pnext->next;
     free(ptr);
   }
  return 0;
}
int main(int argc,char**argv)
{
   Node* head;
   head=Create_Double_link();
   InsertNode(head);
   DeleteNode(head);
   print(head);
   return 0;
}

