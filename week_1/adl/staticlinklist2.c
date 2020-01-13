#include <stdio.h>
#include <stdlib.h>
#include "staticlinklist.h"
int main()
{
    StaticLinkList L;
    InitList(L);
    for (int i = 1; i <= 5; i++)
    {
        ListInsert(L, i, i);
    }
    printf("the list length =%d\n", ListLength(L));
    ListDelete(L, 4);
    for(int I=0;I<10;I++)
    printf("index:%d,cur:%d,data:%d\n",I,L[I].cur,L[I].data);
    int k = MAXSIZE - 1;
    while (L[k].cur != 0)
    {
        k = L[k].cur;
        printf("the %dth data is %d\n", k, L[k].data);
    }
     k = MAXSIZE - 1;
     for(int i=1;i<=4;i++)
    if(L[k].cur != 0)
    {
        printf("%d have been destoried",L[k].cur);
        ListDelete(L,1);
          for(int I=0;I<10;I++)
    printf("index:%d,cur:%d,data:%d\n",I,L[I].cur,L[I].data);
    }

    return 0;
}