/*************************************************************************
	> File Name: Add_First.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月22日 星期三 23时43分27秒
 ************************************************************************/

#ifndef _ADD_FIRST_H
#define _ADD_FIRST_H
typedef struct NODE{
    int data;
    struct NODE*next;
    int n;
}Node;

Node* create();
Node* AddFirst(Node* head);
Node* AddEnd(Node* head);
Node* Find_i(Node* head,int i);
Node* Find_key(Node* head,int key);
Node* change(Node* head,int n,int new);
Node* Delete_i(Node*head,int i);
Node* Delete_key(Node* head,int key);

void Print();
#endif
