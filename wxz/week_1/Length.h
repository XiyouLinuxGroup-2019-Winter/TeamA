/*************************************************************************
	> File Name: Length.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 23时36分02秒
 ************************************************************************/

#ifndef _LENGTH_H
#define _LENGTH_H
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

int CLLength(CLType*head)
{
    CLType*htemp;
    int len=0;
    htemp=head;
    while(htemp)//遍历整个链表
    {
        len++;//累加结点数量
        htemp=htemp->nextNode;//处理下一个结点
    }
    return len;//返回结点数量
}
#endif
