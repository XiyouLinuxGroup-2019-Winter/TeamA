/*************************************************************************
	> File Name: circular_double_linked_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月23日 星期四 23时06分48秒
 ************************************************************************/

#ifndef _CIRCULAR_DOUBLE_LINKED_LIST_H
#define _CIRCULAR_DOUBLE_LINKED_LIST_H
typedef struct NODE{
    struct NODE* next;
    int data;
    int n;//编号
    char name[20];
}Node;

Node* Create(Node* head);
Node* AddFirst(Node* head);
//Node* AddEnd(Node* head);
//Node* Delete_i(Node* head,int i);
Node* Delete_key(Node* head,int key);
void change(Node* head,int n,int new);
//Node* Find_i(Node* head,int i);
Node* Find_key(Node* head,int key);

void Print(Node* head);//历遍链表：
#endif
