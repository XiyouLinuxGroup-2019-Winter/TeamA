/*************************************************************************
	> File Name: no_recursion.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 16时40分59秒
 ************************************************************************/

#include<stdio.h>
//#include "linklist.h"
#include "linkstack.h"
#include "linkstack.c"
typedef struct BiNode
{
 	int data;
        struct BiNode  *lchild, *rchild;
}BiNode, *BiTree;

BiNode *GoLeft(BiNode *T,LinkStack *s)
{
        if (T == NULL)
        {
            return NULL;
        }
        while(T->lchild!=NULL)
        {
            LinkStack_Push(s,(void*)T);
            T = T->lchild;
        }
        return T;
}
void InOrder2(BiNode *T)
{
    BiNode* t=NULL;
    LinkStack* s=LinkStack_Create();
    t=GoLeft(T, s);
    while (t)
    {
        printf("%d ", t->data);
        if (t->rchild != NULL)
        {
            t=GoLeft(t->rchild, s);
        }            
        else if(LinkStack_Size(s)>0)
        {
            t=(BiNode*)LinkStack_Pop(s);
        }                   
        else
        {
            t=NULL;
        }
    }
}
void main()
{
    BiNode t1, t2, t3, t4, t5;

    memset(&t1, 0, sizeof(BiNode));
    memset(&t2, 0, sizeof(BiNode));
    memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
    memset(&t5, 0, sizeof(BiNode));
    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;
    t5.data = 5;
    t1.lchild = &t2;
    t1.rchild = &t3;
    t2.lchild = &t4;
    t3.lchild = &t5;
    InOrder2(&t1);
}



