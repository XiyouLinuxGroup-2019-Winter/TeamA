/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 03时18分28秒
 ************************************************************************/

#include<stdio.h>
#include "tree.h"
#include <stdlib.h>
CBT* TreeInit()
{
    CBT* node;
    if(node=(CBT*)malloc(sizeof(CBT)))
    {
        printf("输入一个根结点数据:\n");
        scanf("%s",&node->data);
        node->left=NULL;
        node->right=NULL;
        if(node!=NULL)
            return node;
        else
            return NULL;
    }
    return NULL;
}
void TreeAdd(CBT* treenode)
{
    CBT* parent,*pnode;
    char menusel;
    char data;
    if(pnode=(CBT*)malloc(sizeof(CBT)))
    {
        printf("输入二叉树结点数据:\n");
        fflush(stdin);
        scanf("%s",&pnode->data);
        pnode->left=NULL;
        pnode->right=NULL;

        printf("输入该结点的父节点数据:");
        fflush(stdin);
        scanf("%s",&data);
        parent=TreeFind(treenode,data);
        if(!parent)
        {
            printf("没有找到该父节点!\n");
            free(pnode);
            return 0;
        }
        printf("1.添加该结点到左子树\n2.添加该结点到右子树\n");
        do{
            menusel=getchar()
            menusel-='0';
            if(menusel==1 || menusel==2)
            {
                if(parent==NULL)
                    printf("不存在父节点，请先设置父节点!\n");
                else
                {
                    switch(menusel)
                    {
                        case 1:
                            if(parent->left)
                                printf("左子树结点不为空！\n");
                            else
                                parent->left=pnode;
                        break;
                        case 2:
                            if(parent->right)
                                printf("右子树结点不为空!\n");
                            else
                                parent->right=pnode;
                        break;
                        default:
                            printf("参数无效!\n");
                    }
                }
            }
        }while(menusel!=1 && menusel!=2)
    }
}
CBT* TreeFind(CBT* treenode,char data)
{
    CBT* ptr;
    if(treenode=＝NULL)
        return NULL;
    else
    {
        if(treenode->data==data)
            return treenode;
        else
        {
            if(ptr=TreeFind(treenode->left,data))
                return ptr;
            else if(ptr=TreeFind(treenode->right,data))
                return ptr;
            else
                return NULL;
        }
    }
}
CBT* TreeLeft(CBT* treenode)
{
    if(treenode)
        return treenode->left;
    else
        return NULL;
}
CBT* TreeRight(CBT* treenode)
{
    if(treenode)
        return treenode->right;
    else
        return NULL;
}
bool TreeIsEmpty(CBT* treenode)
{
    if(treenode)
        return false;
    else
        return true;
}
int TreeDepth(CBT* treenode)
{
    int depleft,depright;
    if(treenode==NULL)
        return 0;
    else
    {
        depleft=TreeDepth(treenode->left);
        depright=TreeDepth(treenode->right);
        if(depleft>depright)
            return depleft+1;
        else
            return depright+1;
    }
}
void TreeFree(CBT* treenode)
{
    if(treenode)
    {
        TreeFree(treenode->left);
        TreeFree(treenode->right);
        treenode=NULL;
        free(treenode);
    }
}
void TreePrint(CBT* treenode)
{
    printf("%c",treenode->data);
}
void TreeDLR(CBT* treenode,void (*TreeNodeData)(CBT* p))//先序遍历
{
    if(treenode)
    {
        TreeNodeData(treenode);
        TreeDLR(treenode->left,TreeNodeData);
        TreeDLR(treenode->right,TreeNodeData);
    }
}
void TreeLDR(CBT* treenode,void (*TreeNodeData)(CBT* p))//中序遍历
{
    if(treenode)
    {
        TreeLDR(treenode->left,TreeNodeData);
        TreeNodeData(treenode);
        treeLDR(treenode->right,TreeNodeData);
    }
}
void TreeLRD(CBT* treenode,void (*TreeNodeData)(CBT* p))
{
    if(treenode)
    {
        TreeLRD(treenode->left,TreeNodeData);
        TreeLRD(treenode->right,TreeNodeData);
        TreeNodeData(treenode);
    }
}

