/*************************************************************************
	> File Name: singly_linked_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月18日 星期二 21时45分19秒
 ************************************************************************/

#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H
#define len sizeof(struct NODE)

typedef struct NODE{
    int data;
    char name[10];
    struct NODE* next;
}Node;

Node *Input(Node* head);
Node* Delete();
int Ruin(Node* head);
void Print();
Node* Find();
//void biaotou();
void Add(Node* head);
#endif
