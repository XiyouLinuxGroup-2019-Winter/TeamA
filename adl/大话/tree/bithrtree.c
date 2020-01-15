#include <stdio.h>
#include <stdlib.h>
#include "bithrtree.h"

//前序遍历～～～中左右
// void PreOrderTraverse(BiThrTree T)
// {

//     if (T == NULL)
//         return;
//     printf("%c", T->data);
//     PreOrderTraverse(T->lchild);
//     PreOrderTraverse(T->rchild);
// }
// Status InOrderTraverse(BiThrTree T)
// {
//     BiThrTree p=T->lchild;
//     while (p!=T)
//     {
//         while (p->LTag==LInk)
//         {
//             p=p->lchild;
//         }
//         printf("%c",p->data);
//         while (p->RTag==Thread&&p->rchild!=T)
//         {
//             p=p->rchild;
//             printf("%c",p->data);
//         }
//         p=p->rchild;

//     }
//     return OK;
// }
// void InOrderTraverse(BiThrTree T)
// {
//     if (T == NULL)
//         return;
//     PreOrderTraverse(T->lchild);
//     printf("%c", T->data);
//     PreOrderTraverse(T->rchild);
// }
// void PostOrderTraverse(BiThrTree T)
// {
//     if (T == NULL)
//         return;
//     PreOrderTraverse(T->lchild);
//     PreOrderTraverse(T->rchild);
//     printf("%c", T->data);
// }

//前序遍历创建二叉树
//注意叶节点的左右孩子都用#
Status CreatBiTree(BiThrTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!*T)
            exit(OVERFLOW); //溢出
        (*T)->data = ch;
        (*T)->LTag = LInk;
        (*T)->RTag = LInk;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
    return OK;
}

void InThreading(BiThrTree B, BiThrTree *pre)
{
    if (!B)
        return;
    InThreading(B->lchild, pre);
    if (!B->lchild)
    {
        B->LTag = Thread;
        B->lchild = *pre;
    }
    if (!(*pre)->rchild)
    {
        (*pre)->RTag = Thread;
        (*pre)->rchild = B;
    }
    *pre = B;
    InThreading(B->rchild, pre);
}
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
    if (!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(OVERFLOW);
    (*Thrt)->LTag = LInk;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);
    if (!T)
    {
        (*Thrt)->lchild = (*Thrt);
        return OK;
    }
    BiThrTree pre;
    pre = (*Thrt);
    (*Thrt)->lchild = T;
    InThreading(T, &pre);
    pre->RTag = Thread;
    pre->rchild = *Thrt;
    (*Thrt)->rchild = pre;
    return OK;
}
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;
    while (p != T)
    {
        while (p->LTag == LInk)//向左下方下降，中间经过的不考虑.整体右下
        {
            p = p->lchild;
        }
        printf("%c", p->data);
        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            printf("%c", p->data);
        }//向右上方抬升
        p = p->rchild;//向右下下降
    }
    return OK;
}
Status REInOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->rchild;
    printf("%c",p->data);//这里不能漏
    while (p != T)
    {
        while (p->LTag == Thread&& p->lchild != T )//左上
        {
            p = p->lchild;
            printf("%c", p->data);
        }
        p = p->lchild;
        while (p->RTag == LInk)
        {
            p = p->rchild;
        }
        printf("%c", p->data);
        
    }
    return OK;
}