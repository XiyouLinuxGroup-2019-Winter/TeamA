/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 21时48分45秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include"seqqueue.h"

int main()
{
    int i=0;
    int a[10];
    SeqQueue* queue=SeqQueue_Create(10);
    if(queue==NULL)
    {
        return -1;
    }
    for(i=0;i<5;i++)
    {
        a[i]=i+1;
        int ret=SeqQueue_Append(queue,&a[i]);
    }

    printf("len:%d\n",SeqQueue_Length(queue));
    printf("header:%d\n",*((int *)SeqQueue_Header(queue)));
    printf("capacity:%d\n",SeqQueue_Capacity(queue));

    while(SeqQueue_Length(queue)>0)
    {
        int tmp=*((int*)SeqQueue_Retrieve(queue));
        printf("tmp:%d\n",tmp);
    }
    SeqQueue_Destroy(queue);

}
/*
 SeqQueue* SeqQueue_Create(int capacity);
void SeqQueue_Destroy(SeqQueue* queue);
void SeqQueue_Clear(SeqQueue* queue);
int SeqQueue_Append(SeqQueue* queue, void* item);
void* SeqQueue_Retrieve(SeqQueue* queue);
void* SeqQueue_Header(SeqQueue* queue);
int SeqQueue_Length(SeqQueue* queue);
int SeqQueue_Capacity(SeqQueue* queue);
 */
