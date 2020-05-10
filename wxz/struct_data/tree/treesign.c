/*************************************************************************
	> File Name: treesign.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 00时52分29秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTNode 
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiNode, *BiTree;
BiNode* BiTree_Create()
{
   BiNode* tmp=NULL;
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        return NULL;
    else
    {
        tmp=(BiNode*)malloc(sizeof(BiNode));
        if(tmp==NULL)
        {
            return NULL;
        }
        tmp->data=ch;
        tmp->lchild=BiTree_Create();
        tmp->rchild=BiTree_Create();
    }
    return tmp;
}
void inOrder(BiNode *root)
{
	if (root != NULL)
	{
		//inOrder(root->lchild);
        printf("%c",root->data);
        inOrder(root->lchild);
		inOrder(root->rchild);
	}
    return ;
}
void FreeTree(BiNode* T)
{
    if(T==NULL)
        return ;
    if(T->lchild!=NULL)
    {
        FreeTree(T->lchild);
        T->lchild=NULL;
    }
    if(T->rchild!=NULL)
    {
        FreeTree(T->rchild);
        T->rchild=NULL;
    }
    if(T!=NULL)
    {
        free(T);
        T=NULL;
    }
}
int main()
{
    
    BiNode* p=NULL;
    p=BiTree_Create();

    inOrder(p);
    //FreeTree(p);
}

