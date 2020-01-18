typedef char TElemType ;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T);
void CreatBiTree(BiTree *T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);