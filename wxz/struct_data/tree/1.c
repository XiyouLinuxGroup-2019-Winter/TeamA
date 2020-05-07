/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月07日 星期四 16时46分39秒
 ************************************************************************/

#include<stdio.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
struct BiNode
{
	int data;
	struct BiNode  *lchild, *rchild;
};
//重新重命名类型
typedef struct BiNode BiNode;
//也是重命名类型 是一个指针的数据类型
typedef struct BiNode *BiTree;
*/


//二叉链表
typedef struct BiNode
{
	int data;
	struct BiNode  *lchild, *rchild;
}BiNode, *BiTree;


//中序遍历
void inOrder(BiNode *root)
{
	if (root != NULL)
	{
		inOrder(root->lchild);
		printf("%d ", root->data);
		inOrder(root->rchild);
	}
	return ;
}
void preOrder(BiNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->lchild);	
		preOrder(root->rchild);
	}
}

void postOrder(BiNode *root)
{
	if (root != NULL)
	{
		postOrder(root->lchild);	
		postOrder(root->rchild);
		printf("%d ", root->data);
	}
}
//引申1
//遍历的本质。。。。。。。

int g_num;
void countLeafNum(BiNode *root)
{
	if (root != NULL)
	{
		
		countLeafNum(root->lchild); //递归遍历左子树，求叶子节点数

		if (root->lchild == NULL && root->rchild==NULL)
		{
			g_num ++;
		}
	
		countLeafNum(root->rchild);//递归遍历右子树，求叶子节点数
	}
}

void countLeafNum2(BiNode *root, int *num)
{
	if (root != NULL)
	{

		countLeafNum2(root->lchild, num); //递归遍历左子树，求叶子节点数

		if (root->lchild == NULL && root->rchild==NULL)
		{
			(*num) ++;
		}

		countLeafNum2(root->rchild, num);//递归遍历右子树，求叶子节点数
	}
}

int GetDepth(BiNode *root)
{
	int depthleft = 0, depthright=0; 
	int depthVal = 0;
	int tmp = 0;

	if (root == NULL)
	{
		depthVal = 0;
		return depthVal;
	}
	//求左子树高度
	depthleft = GetDepth(root->lchild);
	//求右子树高度
	depthright = GetDepth(root->rchild);

	 tmp = ((depthleft>depthright)? depthleft : depthright);
	depthVal = 1 + tmp; 

	return depthVal;
}

BiNode *copyTree(BiNode *T)
{
	BiNode *newLptr = NULL, *newRptr = NULL;
	BiNode *newNode = NULL;
	if (T->lchild != NULL)
	{
		newLptr =copyTree(T->lchild);
	}
	else
	{
		newLptr = NULL;
	}

	if (T->rchild != NULL)
	{
		newRptr = copyTree(T->rchild);
	}
	else
	{
		newRptr = NULL; 
	}
	newNode = (BiNode *)malloc(sizeof(BiNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->lchild = newLptr;
	newNode->rchild = newRptr;
	newNode->data = T->data;

	return newNode;
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
	//t3的左孩子为t5
	inOrder(&t1);
	 printf("\n");
	 preOrder(&t1);
	 printf("\n");
	 postOrder(&t1);
	 g_num = 0;
	 countLeafNum(&t1);
	 printf("g_num: %d \n", g_num);

	 {
		int num = 0;
		countLeafNum2(&t1, &num);
		printf("num: %d \n", num);
	 }

	printf("树的高度为：%d \n", GetDepth(&t1));

	{
		BiNode *root = NULL;
		root =	copyTree(&t1);
		printf("新copy树\n中序遍历:");
		inOrder(root);
	}


	
	system("pause");
}


