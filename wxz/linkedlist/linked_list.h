/*************************************************************************
	> File Name: linkedlist.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 00时17分31秒
 ************************************************************************/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
typedef struct NODE{
    struct NODE*next;
    int data;
    int n;//编号
    char name[20];
}Node;

Node* create();
Node* AddFirst(Node* head);
Node* AddEnd(Node* head);
Node* Delete_i(Node* head,int i);
Node* Delete_key(Node* head,int key);
Node* change(Node* head,int n,int new);
Node* Find_i(Node* head,int i);
Node* Find_key(Node* head,int key);

void Print();//历遍链表：
#endif
