#include <stdio.h>
#include <stdlib.h>
struct link *append(struct link *head);
void displaynode(struct link *head);
void deletememory(struct link *head);
void deletenode(struct link *head,int times);
void insertNode(struct link *head,int n);
void print(struct link *head);
struct link
{
	int data,id;
	char NAME[50];
	struct link *next;
};
int main(void)
{
	char node,a,b;
	int j,pos,times =0;
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
	printf("Do you want to delete a node(Y or N(capital))\n");
	scanf("%c",&a);	
	if(a == 'Y')
		{
			printf("你想要删除哪个节点的数据：\n");
			scanf("%d",&j);
			deletenode(head,j);
			print(head);
		}
	printf("%d new nodes have been appended.\n",times);
	deletememory(head);
	printf("Do you want to insert a node(Y or N(capital))\n");
	scanf(" %c",&b);
	if(b =='Y'){
	printf("你想要在哪插入节点：\n");
	scanf("%d",&pos);
	insertNode(head,pos);
	print(head); 
	}
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
//删除函	
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
//节点删除函数部分
void deletenode(struct link *head,int times){        
	struct  link *p = head,*pr = head;
	int i =0;
	while(i<times&&p!=NULL){       
		pr = p;           
		p = p->next;       
		i++;
	}
	if(p!=NULL){               
		pr->next = p->next;
		free(p);
	} else{
		printf("Node does not exist！\n"); 
	}
}
//不打印函数部分
void print(struct link *head)
{
        struct link *p = head;
        int j =1;
        p = p->next;
        while(p != NULL)
        {
                printf("%d\t%d\t%s\n",j,p->id,p->NAME);
                p = p->next;
                j++;
        }
}
//插入函数部分
void insertNode(struct link *head,int n){    
	struct  link *p = head,*pr = head;
	pr = (struct link*)malloc(sizeof(struct link));  
	printf("input data:\n");
	scanf("%d %s",&pr->id,pr->NAME);
	int i = 0;
        while(i<n&&p!=NULL){ 
        p = p->next;
        i++;
        }
        if(p!=NULL){         
	pr->next = p->next;  
        p->next = pr;
        }else{
        printf("节点不存在！\n");
        }
    }
