#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#define  N  100
 
typedef struct BiTNode  
{  
	char data;  
	struct BiTNode *lchild,*rchild;  
} BiTNode,* BITree;  
 

void postorder(BiTNode*root)
{
    if(root!=NULL)
    {
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%c",root->data);
    }
}

BiTNode* createBiTree(char *pre, char *in, int n)
{
	int i = 0;
	int n1 = 0,n2 = 0;
	int m1 = 0,m2 = 0;
	BiTNode*node = NULL;
	char lpre[N],rpre[N];
	char lin[N],rin[N];
	if (n == 0)
	{
		return NULL;
	}
	node = (BiTNode*)malloc(sizeof(BiTNode));  
	if (node==NULL)  
	{  
		return NULL;  
	}  
	memset(node,0,sizeof(BiTNode)); 
	//先序序列的第一个元素必为根结点
	node->data = pre[0];
	//根据根结点将中序序列分为左子树和右子数
	for (i = 0;i<n;i++)
	{
		if ((i<=n1)&&(in[i]!=pre[0]))
		{
			lin[n1++] = in[i];
		}
		else if(in[i]!=pre[0])
		{
			rin[n2++] = in[i];
		}
	}

	for (i = 1;i < n;i++)
	{
		if (i< (n1+1))//n1代表了左子树的长度
		{
			lpre[m1++] = pre[i];
		}
		else
		{
			rpre[m2++] = pre[i];
		}
	}
	node->lchild = createBiTree(lpre,lin,n1);
	node->rchild = createBiTree(rpre,rin,n2);
 
	return node;
}
 
int main()
{
	char preNode[N];
	char inNode[N];
	int n = 0;
	char ch;
	BiTNode* root=NULL;
	while((ch = getchar())&&ch!='\n')
		preNode[n++] = ch;
	n = 0;
	while((ch = getchar())&&ch!='\n')
		inNode[n++] = ch;
	root = createBiTree(preNode,inNode,n);
 

	postorder(root);
 
	return 0;
}