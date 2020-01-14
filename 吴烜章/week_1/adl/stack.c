#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status Push(Sqstack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}
Status Pop(Sqstack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top--];
    return OK;
}

Status InitStack(Sqstack *S)
{
    // S=(Sqstack*)malloc(sizeof(Sqstack));
    S->top=-1;
}
