#include <stdbool.h>
#define OK 1
#define FALSE 0
typedef bool Status;
typedef int elem_type;
typedef struct Lnode
{
    elem_type data;
    struct Lnode *next;
    struct Lnode *pre;

} Lnode, *Pnode;

typedef struct Linklist
{
    Lnode *head;
    Lnode *tail;
    elem_type sum_node;
} Linklist, *Plist;
Status InitLInkList(Plist *p);
Status AddNode_head(Plist *p, elem_type e);
Status AddNode_tail(Plist *p, elem_type e);
Status DeleteNode_num(Plist *p, int n, elem_type *e);
Status DeleteNode_key(Plist *p, elem_type e);
Status ChangeNode_key(Plist *p, elem_type *e,elem_type cur);
Status SeekNode_num(Plist *p, int n, elem_type *e);
Status SeekNode_key(Plist *p, elem_type e);
Status Traverse(Plist *p, void (*fun)(Lnode *this));
void SeekNode_this(Lnode *this);
void menu(Plist*p);