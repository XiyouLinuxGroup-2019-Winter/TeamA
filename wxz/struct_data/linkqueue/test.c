/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 22时13分42秒
 ************************************************************************/

#include<stdio.h>
#include "linkqueue.h"
int main()
{
    int i,a[10];
    LinkQueue* queue=LinkQueue_Create();
    if(queue==NULL)
    {
        return -1;
    }

    for(i=0;i<5;i++)
    {
        a[i]=i+1;
        LinkQueue_Append(queue,&a[i]);
    }
    printf("the length of queue: %d \n",LinkQueue_Length(queue));
    printf("the header of queue: %d \n",*((int *)LinkQueue_Header(queue)));

	while(LinkQueue_Length(queue)>0)
	{
		printf("%d\n",*((int*)LinkQueue_Retrieve(queue)));
	}

	LinkQueue_Destroy(queue);
}
/*
LinkQueue* LinkQueue_Create();
void LinkQueue_Destroy(LinkQueue* queue);
void LinkQueue_Clear(LinkQueue* queue);
int LinkQueue_Append(LinkQueue* queue, void* item);
void* LinkQueue_Retrieve(LinkQueue* queue);
void* LinkQueue_Header(LinkQueue* queue);
int LinkQueue_Length(LinkQueue* queue);*/
