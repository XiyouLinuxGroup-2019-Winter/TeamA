#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char datatype;
typedef struct Node
{
    datatype data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode, *BiTree;

typedef struct 
{
    BiTree da[1000];
    int top;
}SeqStack;

SeqStack  *InitStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

//判断栈是否为空
int StaIsEmpty(SeqStack *s)
{
    if(s->top == -1)
    return 1;
    else 
    return 0;
}

int push(SeqStack *s, BiTree root) 
{
    BiTree p;
    p = root;
    if(s->top == 999) 
        return 0;
    else {
        s->top++;
        s->da[s->top]=p;
    }
}

void pop(SeqStack *s, BiTree *root) 
{
    BiTree p;
    p = *root;
    if(StaIsEmpty(s))
        return;
    else {
        *root = s-> da[s->top];
        s->top--;
    }
}


//先序创建二叉树
void creat(BiTree *root)
{
    char ch;
    ch = getchar();
    if(ch == '#') {
        *root = NULL;
    }
    else {
        *root = (BiTree) malloc (sizeof(BiTNode));
        (*root) -> data = ch;
        creat(&((*root)->lchild));
        creat(&((*root)->rchild));
    }
}

void preorder(BiTree root, int n)
{
    if(root) {
        printf("(%c,%d)",root->data,n);
        preorder(root->lchild,n+1);
        preorder(root->rchild,n+1);
    }
}

void PreOrder(BiTree root)
{
    SeqStack *s;
    BiTree p;
    s=InitStack();
    p = root;
    while(p != NULL || !StaIsEmpty(s)) {
        while(p != NULL) {
            printf("%c", p->data);
            push(s,p);
            p = p -> lchild;
        }
        if(!StaIsEmpty(s)) {
            pop(s,&p);
            p = p -> rchild;
        }
    }
}

void InOrder(BiTree root) 
{
    SeqStack *s;
    BiTree p;
    s=InitStack();
    p = root;
    while(p != NULL || !StaIsEmpty(s)) {
        while(p!=NULL) {
            push(s,p);
            p = p -> lchild;
        }
        if(!StaIsEmpty(s)) {
            pop(s,&p);
            printf("%c",p->data);
            p = p-> rchild;
        }
    }    
}

int main()
{
    int n;
    BiTree root;
    creat(&root);
    preorder(root,n+1);
    printf("\n");
    return 0;
}
