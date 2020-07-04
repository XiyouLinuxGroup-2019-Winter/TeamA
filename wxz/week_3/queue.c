/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 18时23分28秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
SQT* SQTInit()
{
    SQT* p;
    if(p=(SQT*)malloc(sizeof(SQT)));
    {
        p->head=0;
        p->tail=0;
        return p;
    }
    else
    return NULL;
}
int SQTIsEmpty(SQT* p)
{
    int temp;
    temp=p->head=p->tail;
    return (temp);mZ
    temp=p->tail=len;
    return (temp);
}
void SQTFree(SQT* p)
{
    if(p!=NULL)
        free(p);
}
int InSQT(SQT* p,DATA data)
{
    if(p->tail==len)
    {
        printf("队列已满!\n");
        return 0;
    }
    else
        p->data[p->tail++]=data;
}
DATA *OutSQT(SQT* p)
{
    if(p->head=p->tail)
    {
        printf("队列已空!\n");
        exit(0);
    }
    else
        return &(p->data[p->head++]);
}
DATA *PeekSQT(SQT* p)
{
    if(SQTIsEmpty(p))
    {
        printf("空队列!\n");
        return NULL;
    }
    else
        return &(p->data[p->head]);
}
int SQTLength(SQT* p)
{
    int temp;
    temp=p->tail-p->head;
    return temp;
}
