/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 01时11分13秒
 ************************************************************************/

#include<stdio.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiTNode 
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//按给定的先序序列建立二叉链表
BiTNode* BiTree_Creat12()
{
	BiTNode *tmp = NULL;
	char ch;
	printf("\n请输入字符: ");
	scanf("%c", &ch);
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp->data = ch; //生成根结点
		tmp->lchild = BiTree_Creat12();//构建左子树
		tmp->rchild = BiTree_Creat12();//构建右子数
		return tmp;
	}
}

void preOrder(BiTNode *root)
{
	if (root != NULL)
	{
		printf("%c ", root->data);
		preOrder(root->lchild);	
		preOrder(root->rchild);
	}
}

//按给定的先序序列建立二叉链表
void  BiTree_Free(BiTNode* T)
{
	BiTNode *tmp = NULL;
	if (T!= NULL)
	{
		if (T->rchild != NULL) BiTree_Free(T->rchild);
		if (T->lchild != NULL) BiTree_Free(T->lchild);
		if (T != NULL)
		{
			free(T); 
			T = NULL;
		}
	}
}


void main()
{
	int nCount = 0, depthval = 0;
	BiTNode * my = BiTree_Creat12();
	printf("\n非递归算法c++访问\n");
	//InOrder(my);
	preOrder(my);

	BiTree_Free(my);
	printf("树释放完毕\n");

	printf("\n");
	system("pause");
}
