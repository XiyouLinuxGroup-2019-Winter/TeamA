/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月10日 星期日 01时51分00秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root){
	if (root == NULL){
		return;
	}

	printf("%c",root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

BinaryNode* CreateBinaryTree(){

	fflush(stdin);
	char ch;
	scanf("%c",&ch);

	BinaryNode* node;

	if (ch == '#'){
		node = NULL;
	}
	else{

		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		node->ch = ch;
		node->lchild = CreateBinaryTree();
		node->rchild = CreateBinaryTree();
	}


	return node;
}

int main(void){

	//创建树
	BinaryNode* root = CreateBinaryTree();
	//打印树
	Recursion(root);


	printf("\n");
	system("pause");
	return 0;
}

