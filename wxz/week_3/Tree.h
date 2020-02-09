/*************************************************************************
	> File Name: Tree.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 01时02分32秒
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H
#include <stdbool.h>
typedef struct item{
    char petname[20];mZ
    Node* root;
    int size;
}Tree;

void TreeInit(Tree* ptree);
bool TreeIsEmpty(Tree* ptree);
bool TreeIsFull(Tree* ptree);
int TreeCount(Tree* ptree);
bool AddItem(Item* pi,Tree* ptree);
bool TreeFind(Item* pi,Tree* ptree);
bool DeleteItem(Item* pi,Tree* ptree);
void Traverse(Tree* ptree,void (*pfun)(Item item));
void DeleteAll(Tree* ptree);



#endif
