#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
int main()
{
    SqQueue q;
    InitQueue(&q);
    QElemType e;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d",&e);
        EnQueue(&q,e);
    }
    for (int i = 0; i < 4; i++)
    {
        DeQueue(&q,&e);
        printf("%d have been deleted from thr queue\n",e);
        printf("now the length of queue is %d\n",QueueLength(q));
    }

    
    
    return 0;
}