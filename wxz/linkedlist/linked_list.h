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
    int i;
    char name[20];
}Node;

Node* create();
Node* Addfirst();
Node* AddEnd();
Node* Delete_i();
Node* Delete_key();
Node* change();
Node* Find_i();
Node* Find_key();

void Print();//历遍链表：
#endif
