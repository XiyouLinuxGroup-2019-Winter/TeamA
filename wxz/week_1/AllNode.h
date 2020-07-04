/*************************************************************************
	> File Name: AllNode.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 23时39分01秒
 ************************************************************************/

#ifndef _ALLNODE_H
#define _ALLNODE_H
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


void CLTypeAllNode(CLType* head)
{
    CLType*htemp;
    Data nodeData;
    htemp=head;
    printf("当前链表共有%d个结点，链表所有数据如下:\n",CLLength(head));
    while(htemp)//循环处理链表每个结点
    {
        nodeData=htemp->nodeData;//获取结点数据
        printf("结点(%s %s %d)\n",nodeData.key , nodeData.name ,nodeData.age);
        htemp=htemp->nextNode;//处理下一结点
    }
}
#endif
