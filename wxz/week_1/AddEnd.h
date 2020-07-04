/*************************************************************************
	> File Name: AddEnd.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 18时08分56秒
 ************************************************************************/

#ifndef _ADDEND_H
#define _ADDEND_H

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


CLType* CLAddEnd(CLType* head,Data nodeData)
{
    CLType* node,*htemp;
    if(!(node=(CLType*)malloc(sizeof(CLType))))
    {
        printf("申请内存分配失败！\n");
        return NULL:
    }
    else
    {
        node->nodeData=nodeData;
        node->nextNode=NULL; //设置节点指针为空，即为尾表
        if(head==NULL)
        {
            head=node;
            return head;
        }
        htemp=head;
        while(htemp->nextNode!=NULL)//查找链表的尾部
        {
            htemp=htemp->nextNode;
        }
        htemp->nextNode=node;
        return head;
    }

#endif
