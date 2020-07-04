/*************************************************************************
	> File Name: linkedlist.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 03时08分05秒
 ************************************************************************/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* create();
void Free(Node* p);
Node* search(int key);
void insert(Node* p);
void delete(Node* p);
void traverse(void (*visit)(Node*));
void destory();
void push(Node* p);
Node* pop();


#endif
