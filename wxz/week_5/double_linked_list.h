/*************************************************************************
	> File Name: double_linked_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月20日 星期四 01时14分58秒
 ************************************************************************/

#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
typedef struct NODE{
    int data;
    struct NODE* next;
    struct NODE* pro;
    int n=0;
}Node;

void Create(Node* head);
void Print(Node* head);
void Delete(Node* head,int i);
void Add(Node* head,int i);
void reverse(Node* head);



#endif
