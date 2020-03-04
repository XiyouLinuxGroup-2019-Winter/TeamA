#include<stdio.h>
struct f
{
	int data;
	char name[11];
	struct f *next;
};                                    
struct f *creat(void)             
{
	struct f *head,*p,*end;
	head=end=(struct f*)malloc(sizeof(struct f));
	printf("请输入学号以及你的姓名！");
	p=(struct f*)malloc(sizeof(struct f));
	scanf("%d %s",&p->data,p->name);
	while(p->data!=0)
	{
		end->next=p;
		end=p;
		printf("请输入学号以及你的姓名！");
		p=(struct f*)malloc(sizeof(struct f));
	    scanf("%d %s",&p->data,p->name);  
	}
	end->next=NULL;
	free(p);
	return head; 
} 
void print(struct f*head)     
{
	head=head->next;
	while(head!=NULL)
	{
		printf("%d %s\n",head->data,head->name);
		head=head->next; 
	}
} 
int main()      
{
	struct f *head;
	head=creat();
	print(head);
}
