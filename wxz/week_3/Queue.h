/*************************************************************************
	> File Name: Queue.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 14时11
    分07秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdbool.h>
#define max 10
typedef struct node{
    int item;
    struct node* next;
}Node;
typedef struct queue{
     Node* head;
    Node* tail;
    int n;
}Queue;

void QueueInit(Queue* p);
bool QueueIsFull(Queue* p);
bool QueueIsEmpty(Queue* p);
int QueueCount(Queue* p);
//bool QueueIn(int item,Queue* p);
//bool QueueDelete(int *item,Queue* p);
void QueueFree(Queue* p);
#endif
