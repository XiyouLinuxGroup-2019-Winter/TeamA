#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct list {
		int id;			/*标识这个元素方便查找*/
		char data[20];		/* 链表中包含的元素 */
		struct list *next;	/* 指向下一个结点的指针 
	        struct list *prev;	/* 指向前一个结点的指
	    }

static struct list *list_head = NULL;
static int list_id = 0;

static void list_add(struct list **head, struct list *list)
{
	struct list *temp;
	if(NULL == *head)//判断是否为空
		{
			
			*head = list;			
			(*head)->next = NULL;
			(*head)->prev = NULL
                 }
	else
        {
	
		temp = *head;	
		while(temp)	
		{
		/* 将新结点插入到链表尾部 */
                 if(NULL == temp->next)
	         {
			temp->next = list;
		        list->next = NULL;
	        	list->prev = temp;
			return;
		}
		temp = temp->next;
              	}
	}
}
static struct list *find_list_tail(struct list **head)
{
		struct list *temp = *head;
		struct list *p = NULL;
		if(NULL==temp)
		{
			return NULL;
		}
		else
		{
			while(temp)
			{
				p=temp;
				temp=temp->next;
				if(NULL==temp)
					return p;
			}
		}
		return NULL;
}
static void list_print_head(struct list **head)
{	
		struct list *temp;
		 
		temp = *head;
			
		printf("list information form head:\n");
		while(temp)
		{
	                    printf("\tlist %d : %s\n", temp->id, temp->data);
			    temp = temp->next;
                }
}

static void list_print_tail(struct list **tail)
{	
		struct list *temp;
		 
		temp = *tail;
			 
		printf("list information form tail:\n");
	        while(temp)
		{
             		printf("\tlist %d : %s\n", temp->id, temp->data);
		        temp = temp->prev;
	        }
}
int main(int argc, char *argv[])
{
	int i = 0;
	struct list *lists = NULL;			 
	/* 分配10个元素 */
	lists = malloc(sizeof(struct list) * 10);
	if(NULL == lists)
	{
		printf("malloc error!\n");	
		return -1;
        }


	for(i = 0; i < 10; i++)
	{
             lists[i].id = list_id++;
	     sprintf(lists[i].data, "TECH-PRO - %d", i);
	     list_add(&list_head, &lists[i]);
	}
	 
	/* 从头部遍历链表，把链表中每个元素的信息都打印出来 */
	list_print_head(&list_head);
		 
        /* 找到链表尾部 */
	list_tail = find_list_tail(&list_head);
			 
	/* 从尾部遍历链表，把链表中每个元素的信息都打印出来 */
	list_print_tail(&list_tail);
				 
	return 0;
}

