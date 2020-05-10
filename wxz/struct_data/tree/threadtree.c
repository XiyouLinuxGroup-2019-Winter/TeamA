/*************************************************************************
	> File Name: threadtree.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月10日 星期日 02时07分12秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {Link,Thread} Flag;

typedef struct BiThrNode{
    char data;
    struct BiThrNode* lchild,*rchild;
    Flag LTag;
    Flag RTag;
}BiThrNode,*BiThrTree;

int visit(char c)
{
    printf("%c",c);
    return 1;
}
int CreateBiThrTree(BiThrTree* T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiThrTree)malloc(sizeof(BiThrNode));
        if(*T==NULL)
            exit(1);
        (*T)->data=ch;

        CreateBiThrTree(&(*T)->lchild);
        if((*T)->lchild!=NULL)
            (*T)->LTag=Link;
        if((*T)->rchild!=NULL)
            (*T)->RTag=Link;
    }
    return 1;
}
BiThrTree pre;
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(p->lchild==NULL)
        {
            p->RTag=Thread;
            p->lchild=pre;
        }
        if(pre->rchild==NULL)
        {
            pre->RTag=Thread;
            pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild);
    }
}
int InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{
    *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
    if(*Thrt==NULL)
        exit(1);

    (*Thrt)->LTag=Link;
    (*Thrt)->RTag=Thread;
    (*Thrt)->rchild=(*Thrt);
    if(T==NULL)
        (*Thrt)->lchild=*Thrt;
    else
    {
        (*Thrt)->lchild=T;
        pre=(*Thrt);
        InThreading(T);
        pre->rchild=*Thrt;
        pre->RTag=Thread;
        (*Thrt)->rchild=pre;
    }
    return 0;
}
int InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p=T->lchild;
    while(p!=T)
    {
        while(p->LTag==Link)
            p=p->lchild;
        if(!visit(p->data))
            return -1;
        while(p->RTag==Thread&&p->rchild!=T)
        {
            p=p->rchild;
            visit(p->data);
        }
        p=p->rchild;
    }
    return 0;
}
int main()
{
    BiThrTree H,T;
	printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* 按前序产生二叉树 */
	InOrderThreading(&H,T); /* 中序遍历,并中序线索化二叉树 */
	printf("中序遍历(输出)二叉线索树:\n");
	InOrderTraverse_Thr(H); /* 中序遍历(输出)二叉线索树 */
	printf("\n");
}
