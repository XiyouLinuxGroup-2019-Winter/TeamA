/*************************************************************************
	> File Name: AddFirst.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 19时05分53秒
 ************************************************************************/
 
#ifndef _ADDFIRST_H
#define _ADDFIRST_H
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

CLType*CLAddFirst(CLType*head,Data nodeData)
{
    CLType* node;
    if(!(node=(CLType*)malloc(sizeof(CLType))))
    {
        printf("申请内存失败！\n");
        return NULL:
    }
    else
    {
        node->nodeData=nodeData;
        node->nextNode=head;//指向头指针所指结点
        head=node;//头指针指向新增结点
        return head;
    }
}
#endif
