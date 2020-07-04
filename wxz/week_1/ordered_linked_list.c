/*************************************************************************
	> File Name: ordered_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 22时46分31秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE{
    struct NODE *link;
    int     value;
}Node;
int sll_insert(Node** linkp,int new_value)
{
    Node* current;
    Node* new;
    
    while((current=*linkp)!=NULL && current->value<new_value)
        linkp=&current->link;

    new=(Node*)malloc(sizeof(Node));
    if(new==NULL)
        return 0;
    new->value=new_value;


    new->link=current;
    *linkp=new;
    return 1;
}


