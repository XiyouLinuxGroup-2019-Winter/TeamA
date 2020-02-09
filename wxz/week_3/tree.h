/*************************************************************************
	> File Name: tree.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 03时10分31秒
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H
#include <stdbool.h>
#define len 20
typedef struct CBT{
    char data;
    struct CBT* left;
    struct CBT* right;
}CBT;
CBT* TreeInit();
void TreeAdd(CBT* treenode);
CBT* TreeFind(CBT* treenode,char data);
CBT* TreeLeft(CBT* treenode);
CBT* TreeRight(CBT* treenode);
bool TreeIsEmpty(CBT* treenode);
int TreeDepth(CBT* treenode);
void TreeFree(CBT* treenode);
void TreeDLR(CBT* treenode,void (*TreeNodeData)(CBT* p));
void TreeLDR(CBT* treenode,void (*TreeNodeData)(CBT* p));
void TreeLRD(CBT* treenode,void (*TreeNodeData)(CBT* p));
void TreeLevel(CBT* treenode,void (*TreeNodeData)(CBT* p));


#endif
