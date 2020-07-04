/*************************************************************************
	> File Name: treetraverse.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月07日 星期四 15时09分00秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BiNode{
    int data;
    struct BiNode* lchild,*rchild;
}BiNode,*BiTree;

void preOrder(BiNode* root)
{
    if(root==NULL)
        return ;
    printf("%d ",root->data);
    
    //遍历左子树
    preOrder(root->lchild);
    //遍历右子树
    preOrder(root->rchild);
}
//中序遍历
void inOrder(BiNode* root)
{
    
    if(root==NULL)
        return ;
    
    //遍历左子树
    inOrder(root->lchild);
    printf("%d ",root->data);
    //遍历右子树
    inOrder(root->rchild);
}
//后序遍历
void posOrder(BiNode* root)
{
    
    if(root==NULL)
        return ;
    //遍历左子树
    posOrder(root->lchild);
    //遍历右子树
    posOrder(root->rchild);
    printf("%d ",root->data);
}
int sum;
void countLeaf(BiNode* T)
{
    if(T!=NULL)
    {
        if(T->lchild==NULL && T->rchild==NULL)
        {
            sum++;
        }
        if(T->lchild)
        {
            countLeaf(T->lchild);
        }
        if(T->rchild)
        {
            countLeaf(T->rchild);
        }
    }
}

void countLeaf2(BiNode* T,int* sum)
{
    if(T!=NULL)
    {
        if(T->lchild==NULL && T->rchild==NULL)
        {
            (*sum)++;
        }
        if(T->lchild)
        {
            countLeaf2(T->lchild,sum);
        }
        if(T->rchild)
        {
            countLeaf2(T->rchild,sum);
        }
    }
}
int GetDepth(BiNode* T)
{
    int depthleft=0;
    int depthright=0;
    int depthvar=0;
    if(T==NULL)
    {
        depthvar=0;
        return depthvar;
    }
    depthleft=GetDepth(T->lchild);
    depthright=GetDepth(T->rchild);
    depthvar=1+((depthleft>depthright)? depthleft:depthright);
    return depthvar;
}
BiNode* CopyTree(BiNode* T)
{
    BiNode* newNode=NULL;
    BiNode* newLp=NULL;
    BiNode* newRp=NULL;
    if(T==NULL)
        return NULL;

    if(T->lchild!=NULL)
    {
        newLp=CopyTree(T->lchild);
    }
    else
        newLp=NULL;
    if(T->rchild!=NULL)
    {
        newRp=CopyTree(T->rchild);
    }
    else
        newRp=NULL;

    newNode=(BiNode*)malloc(sizeof(BiNode));
    if(newNode==NULL)
        return NULL;
    newNode->lchild=newLp;
    newNode->rchild=newRp;
    newNode->data=T->data;

    return newNode;

}


int main()
{
    BiNode t1,t2,t3,t4,t5;
    memset(&t1,0,sizeof(BiNode));
    memset(&t2,0,sizeof(BiNode));
    memset(&t3,0,sizeof(BiNode));
    memset(&t4,0,sizeof(BiNode));
    memset(&t5,0,sizeof(BiNode));


    t1.data=1;
    t2.data=2;
    t3.data=3;
    t4.data=4;
    t5.data=5;

    t1.lchild=&t2;
    t1.rchild=&t3;
    t2.lchild=&t4;
    t3.lchild=&t5;

    //printf("%d\n",Depth(&t1));
    {
        BiNode* root=CopyTree(&t1);
        printf("copy inOrder\n");
        inOrder(root);
    }

    sum=0;
    countLeaf(&t1);
    printf("sum:%d \n",sum);

    {
        int mysum=0;
        countLeaf2(&t1,&mysum);
        printf("mysum:%d \n",mysum);
    }

    printf("树的高度是:%d\n",GetDepth(&t1));


    printf("preOrder\n");
    preOrder(&t1);
    printf(" older inOrder\n");
    inOrder(&t1);

    printf("posOrder\n");
    posOrder(&t1);
    printf("\n");
}
