/*************************************************************************
	> File Name: DeleteNode.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 23时29分22秒
 ************************************************************************/

#ifndef _DELETENODE_H
#define _DELETENODE_H
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

int CLDelteNode(CLType*head,char*key)
{mZ    CLType*node,*htemp;
    htemp=head;
    node=head;
    while(htemp)
    {
        if(strcmp(htemp->nodeData.key , key)==0)//找到关键字，执行删除操作
        {
            node->nextNode=htemp->nextNode;//使前一结点指向当前结点的下一结点
            free(htemp);
            return 1;
        }
        else
        {
            node=htemp;//指向当前结点
            htemp=htemp->nextNode;//指向下一结点
        }
    }
 return 0;//未删除
}
#endif
