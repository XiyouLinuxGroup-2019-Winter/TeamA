/*************************************************************************
	> File Name: linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 17时50分15秒
 ************************************************************************/

#include<stdio.h>

typedef struct {
    char key[10];//学号
    char name[20];
    int age;
}Data;

typedef struct Node
{
    Data nodeData;//引用结构体作为下一个节点的信息存储
    struct Node *nextNode;//用来指向下一个节点
}CLType;

