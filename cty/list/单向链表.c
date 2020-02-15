#include <stdio.h>
#include <stdlib.h>
struct link *append(struct link *head);
void displaynode(struct link *head);
void deletememory(struct link *head);

struct link
{
	int data;
	struct link *next;
};
int main(void)
{
	char node;
	int times =0;
	struct link *head = NULL;
	printf("Do you want to append a node(Y or N(capital))?");
	scanf("%c",&node);
	while(node == 'Y')
	{
		head=append(head);
		displaynode(head);
		printf("Do you want to append a node(Y or N(capital))?");
		scanf("%c",&node);
		times ++;
	}	
	printf("%d new nodes have been appended.\n",times);
	deletememory(head);
}
//添加函数部分
struct link *append(struct link *head)
{
 	struct link *p = NULL,*pr = head;
	int data;
	p = (struct link *)malloc(sizeof(struct link));
	if(p == NULL)
	{
		printf("No enough momery to allocate.\n");
		exit(0);
	}
	if(head == NULL)
	{
		head = p;
	}else
		{
			while(pr->next != NULL)
			{
				pr = pr ->next;
			}
			pr ->next = p;
		}
	printf("Please input node data:");
	scanf("%d",&data);
	p->data = data;
	p->next = NULL;
	return head;
}
//展示函数部分
void displaynode(struct link *head)
{
	struct link *p = head;
	int num = 1;
	while(p != NULL)
	{
		printf("%5d%10d\n",num,p->data);
		p = p ->next;
		num++;
	}
}
//删除函数部分
void deletememory(struct link *head)
{
	struct link *p =head,*pr =NULL;
	while(p !=NULL)
	{
		pr = p;
		p = p ->next;
		free(pr);
	}
}
