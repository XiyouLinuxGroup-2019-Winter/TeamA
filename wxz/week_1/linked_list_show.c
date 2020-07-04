/*************************************************************************
	> File Name: linked_list_show.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 23时57分42秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char key[10];//学号
    char name[20];
    int age;
}Data;

typedef struct Node{
    Data nodeData;//引用结构体作为下一个节点的信息存储
    struct Node *nextNode;//用来指向下一个节点
}CLType;

CLType*CLAddEnd(CLType*head,Data nodeData)//追加结点
{
    CLType* node,*htemp;
    if(!(node=(CLType*)malloc(sizeof(CLType))))
    {
        printf("申请内存分配失败！\n");
        return NULL;
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
}

CLType*CLAddFirst(CLType*head,Data nodeData)
{
    CLType* node;
    if(!(node=(CLType*)malloc(sizeof(CLType))))
    {
        printf("申请内存失败！\n");
        return NULL;
    }
    else
    {
        node->nodeData=nodeData;
        node->nextNode=head;//指向头指针所指结点
        head=node;//头指针指向新增结点
        return head;
    }
}

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

CLType* CLInsertNode(CLType*head,char*findkey,Data nodeData)
{
    CLType* Node,*nodetemp;
    if(!(Node=(CLType*)malloc(sizeof(CLType))))
    {
        printf("分配内存失败！\n");
        return 0;
    }
    Node->nodeData=nodeData;
    nodetemp=CLFindNode(head,findkey);
    if(nodetemp)//若找到插入的结点
    {
        Node->nextNode=nodetemp->nextNode;//新插入结点指向关键结点的下一个结点
        nodetemp->nextNode=Node;//设置关键结点指向新插入结点
    }
    else
    {
        printf("未找到正确的插入位置!\n");
        free(Node);
    }
    return head;
}


int CLDelteNode(CLType*head,char*key)
{    CLType*node,*htemp;
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


void CLAllNode(CLType* head)
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

int main()
{
    CLType*node,*head=NULL;
    Data nodeData;
    char key[10],findkey[10];

    printf("链表测试，请输入链表中的数据，格式为：关键字　姓名　年龄\n");
    do
    {
        fflush(stdin);
        scanf("%s",nodeData.key);
        if(strcmp(nodeData.key , "0")==0)
            break;
        else
        {
            scanf("%s %d",nodeData.name,&nodeData.age);
            head=CLAddEnd(head,nodeData);//在尾部添加结点
        }
    }while(1);

    CLAllNode(head);

    printf("\n演示插入结点，输入插入位置的关键字:");
    fflush(stdin);
    scanf("%s",key);
    CLDelteNode(head,key);
    CLAllNode(head);

    printf("\n演示在链表中查找，输入查找关键字:");
    fflush(stdin);
    scanf("%d",key);
    node=CLFindNode(head,key);
    if(node)
    {
        nodeData=node->nodeData;
        printf("关键字%s对应的结点为(%s %s %d)\n",key,nodeData.key,nodeData.name,nodeData.age);
    }
    else
     printf("在链表中未找到关键字为%s的结点!\n",key);
}
