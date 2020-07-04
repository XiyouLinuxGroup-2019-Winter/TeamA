/*************************************************************************
	> File Name: InsertNode.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 21时56分23秒
 ************************************************************************/

#ifndef _INSERTNODE_H
#define _INSERTNODE_H
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

CLType* CLInsertNode(CLType*head,char*findkey,Data nodeData)
{
    CLType* Node,*nodetemp;
    if(!(node=(CLType*)malloc(sizeof(CLType))))
    {
        printf("分配内存失败！\n");
        return 0;
    }
    Node->nodeData=nodeData;
    nodetemp=CLFindNode(head,findkey);
    if(nodetemp)//若找到插入的结点
    {
        node->nextNode=nodetemp->nextNode;//新插入结点指向关键结点的下一个结点
        nodetemp->nextNode=node;//设置关键结点指向新插入结点
    }
    else
    {
        printf("未找到正确的插入位置!\n");
        free(node);
    }
    return head;
}
#endif
