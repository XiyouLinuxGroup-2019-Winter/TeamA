#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef enum
{
    LInk,
    Thread
} PointerTag;
typedef char TElemType;
typedef struct BiThrNode
{
    TElemType data;
    PointerTag LTag;
    PointerTag RTag;
    struct BiThrNode *lchild, *rchild;
} BiThrNode, *BiThrTree;

// void PreOrderTraverse(BiThrTree T);
Status CreatBiTree(BiThrTree *T);
Status InOrderTraverse(BiThrTree T);
// void PostOrderTraverse(BiThrTree T);
void InThreading(BiThrTree B,BiThrTree*pre);
Status InOrderTraverse_Thr(BiThrTree T);
Status InOrderThreading(BiThrTree*Thrt,BiThrTree T);
Status REInOrderTraverse_Thr(BiThrTree T);