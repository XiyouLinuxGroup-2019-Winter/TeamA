/*************************************************************************
	> File Name: tree_show.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 00时35分51秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
//#include <conin.h>
#include "tree.h"
int main()
{
    CBT* root=NULL;
    char menual;
    void (*TreeNodeData1)();
    TreeNodeData1=TreeNodeData;

    root=TreeInit();

    do{
        printf("请选择添加二叉树的结点\n");
        printf("0.退出\t");
        printf("1.添加二叉树的结点\n");
        menual=getchar();
        switch(menual)
        {
            case '1':
                TreeAdd(root);
                break;
            case '0':
                break;
            default:
                ;
        }
    }while(menual!='0');

    do{
        printf("请选择历遍二叉树:\n");
        printf("1.先序历遍 DLR\n");
        printf("2.中序历遍 LDR\n");
        printf("3.后序历遍 LRD\n");
        printf("4.按层历遍\n");
        menual=getchar();
        switch(menual)
        {
            case '0':
                break;
            case '1':
                printf("\n先序历遍结果：");
                TreeDLR(root,TreeNodeData1);
                printf("\n");
                break;
            case '2':
                printf("\n中序历遍:");
                TreeLDR(root,TreeNodeData1);
                printf("\n");
                break;
            case '3':
                printf("\n后序历遍：");
                TreeLRD(root,TreeNodeData1);
                printf("\n");
                break;
            case '4':
                printf("\n按层历遍：");
                TreeLevel(root,TreeNodeData1);
                printf("\n");
                break;
            default:
                ;
        }
    }while(menual!='0');

    printf("\n二叉树深度为:%d\n",TreeDepth(root));

    TreeFree(root);
    root=NULL;
}
