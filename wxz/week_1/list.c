/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 16时34分17秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "list.h"

//局部函数原型
static void CopyToNode(Item item,Node* pnode);

//把列表设置为空列表
void InitializeList(List* plist)
{
    *plist=NULL;
}

//如果列表为空则返回为真
bool ListIsEmpty(const list*plist)
{
    if(*plist==NULL)
    return true;
    else
    return false;
}

//如果列表已满返回真
bool ListIsFull(const list*plist)
{
    Node*pt;
    bool full;
    pt=(Node*)malloc(sizeof(Node));
    if(pt==NULL)
    full=true;
    else
    full=false;
    free(pt);
    return full;
}

//返回节点数
unsigned int ListItemCount(const List*plist)
{
    unsigned int count=0;
    Node*pnode=*plist;//设置到列表的开始处
    while(pnode!=NULL)
    {
        ++count;
        pnode=pnode->next;//把l设置为下一个节点
    }
    return count;
}

//创建存放项目的节点，并把它添加到由plist指向的列表尾部
bool AddItem(Item item,List*plist)
{
    Node*pnew;
    Node*scan=*plist;
    pnew=(Node*)malloc(sizeof(Node));
    if(pnew==NULL)
    return false;//失败时退出函数

    CopyToNode(item,pnew);
    pnew->next=NULL:
    if(scan==NULL)
    *plist=pnew;//空列表因此把pnew放在列表头部
    elsｅ
    {
        while(scan->next!=NULL)
            scan=scan->next;//找到列表结尾
        scan->next=pnew;//把pnew添加到结尾处
    }
    return true;
}



//访问每个节点并对它们分别执行由pfun指向的函数
void Traverse(const list* plist,void (*pfun)(Item,item))
{
    Node* pnode=*plist;//设置到列表的开始处
    while(pnode!=NULL)
    {
        (*pfun)(pnode->item);//把函数作用于列表中的项目
        pnode=pnode->next;//前进到下一项
    }
}


//释放由malloc()分配的内存
//把列表指针设置为NULL
void EmptyTheList(List* plist)
{
    Node* psave;
    while(*plist!=NULL)
    {
        psave=(*plist)->next;//保存下一个节点的地址
        free(*plist);
        *plist=psave;//前进到下一个节点处
    }
}


//局部函数定义
//把一个项目复制一个节点中
static void CopyToNode(Item item,Node*pnode)
{
    pnode->item=item;//结构复制：
}
