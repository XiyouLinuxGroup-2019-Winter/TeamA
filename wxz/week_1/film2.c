/*************************************************************************
	> File Name: film2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时35分43秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 45
struct file{
    char title[size];
    int rating;
    struct film* next;//指向链表的下一个结构
};
int main()
{
    struct film*head=NULL;
    struct film*prev,*current;
    char input[size];

    puts("Enter first movie title:");
    while(fgets(input,size,stdin)!=NULL && input[0]!='\0')
    {
        current=(struct film*)malloc(sizeof(struct film));
        if(head=NULL)
        head=current;//第一个结构

        else
            prev->next=current;

        current->next=NULL;
        strcpy(current->title,input);
        puts("Enter your ratiing <0-10>:");
        scanf("%d",&current->rating);
        while(getchar()!='\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev=current;
    }

    //给出电影列表
    if(head=NULL)
        printf("No data entered.");
    else
        printf("Here is the movie list:\n");
    current=head;
    while(current!=NULL)
        {
            printf("Movie:%s rating:%d\n",current->title,current->rating);
            current=current->next;
        }
    
    //释放所分配的内存
    current=head;
    while(current!=NULL);
        {
            free(current);
            current=current->next;
        }
    printf("bye!\n");
}

