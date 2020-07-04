/*************************************************************************
	> File Name: double_linked_list.h
	> Author: mZ	> Mail: 
	> Created Time: 2020年02月09日 星期日 16时55分14秒
 ************************************************************************/

#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
typedef struct node{
    int n;
    int data;
    struct node* pre,*next;
}Node;
Node* Create();
void Print(Node* p);
void Destory(Node* p);
void Insert(Node* p);
void Delete(Node* p);
#endif
