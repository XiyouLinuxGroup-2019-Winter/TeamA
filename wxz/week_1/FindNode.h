/*************************************************************************
	> File Name: FindNode.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 21时50分06秒
 ************************************************************************/

#ifndef _FINDNODE_H
#define _FINDNODE_H
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

CLType*CLFindNode(CLType*head,char*key)
{
    CLType*htemp;
    htemp=head;//保存链表头指针
    while(htemp)//若结点有效不为空，则进行查找
    {
        if(strcmp(htemp->nodeData.key , key)==0)//若结点关键字与传入关键字相同
        {
            return htemp;//返回该结点指针
        }
        htemp=htemp->nextNode;//处理下一个结点
    }
    return NULL;//返回空指针
}
#endif
