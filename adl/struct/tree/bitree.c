#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

//前序遍历～～～中左右
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PreOrderTraverse(T->lchild);
    printf("%c", T->data);
    PreOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    printf("%c", T->data);
}


//前序遍历创建二叉树
//注意叶节点的左右孩子都用#
void CreatBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c",&ch);
    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(__overflow);//溢出
        (*T)->data=ch;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
    
}