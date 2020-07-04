/*************************************************************************
	> File Name: linked_list.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月20日 星期四 15时58分17秒
 ************************************************************************/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
typedef struct NODE{
    int data;
    struct NODE next;
}Node;
int n;
Node* Create();
void Print(Node* head);
Node* Add(Node* head);
void Delete(Node* head,int i);



#endif
