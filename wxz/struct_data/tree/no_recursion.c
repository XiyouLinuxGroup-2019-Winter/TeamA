/*************************************************************************
	> File Name: no_recursion.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 16时40分59秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "linkstack.c"

typedef struct BiNode
{
 	char data;
    struct BiNode  *lchild, *rchild;
}BiNode, *BiTree;

typedef struct BiTreeStackNode
{
    BiNode* root;
    int flag;
}BiTreeStackNode;

BiTreeStackNode* CreateBiTreeStackNode(BiNode* node,int flag)
{
    BiTreeStackNode* newnode=(BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
    newnode->root=node;
    newnode->flag=flag;
    return newnode;
}

void NoRecursion(BiNode* root)
{
    LinkStack* stack=LinkStack_Create();
    LinkStack_Push(stack,(void*)CreateBiTreeStackNode(root,0));

    while(LinkStack_Size(stack)>0)
    {
        //先弹出栈顶元素
        BiTreeStackNode* node=(BiTreeStackNode*)LinkStack_Top(stack);
        LinkStack_Pop(stack);

        if(node->root==NULL)
        {
            continue;
        }
        if(node->flag==1)
        {
            printf("%c",node->root->data);
        }
        else
        {
            //中序遍历
            LinkStack_Push(stack,(void*)CreateBiTreeStackNode(node->root->rchild,0));

            LinkStack_Push(stack,(void*)CreateBiTreeStackNode(node->root->lchild,0));
            node->flag=1;
            LinkStack_Push(stack,(void*)node);
        }

        
    }

}
void Recursion(BiNode* root)
{
    if(root==NULL)
    return ;
    printf("%c",root->data);

    Recursion(root->lchild);
    Recursion(root->rchild);

}
int main()
{
    BiNode node1={'A',NULL,NULL};
    BiNode node2={'B',NULL,NULL};
    BiNode node3={'C',NULL,NULL};
    BiNode node4={'D',NULL,NULL};
    BiNode node5={'E',NULL,NULL};
    BiNode node6={'F',NULL,NULL};
    BiNode node7={'G',NULL,NULL};
    BiNode node8={'H',NULL,NULL};

   node1.lchild=&node2;
   node1.rchild=&node6; 
node2.rchild=&node3;
node3.lchild=&node4;
node3.rchild=&node5;
node6.rchild=&node7;
node7.lchild=&node8;

    NoRecursion(&node1);
    printf("\n");
    Recursion(&node1);
    printf("\n");
}

/*BiNode *GoLeft(BiNode *T,LinkStack *s)
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
*/


