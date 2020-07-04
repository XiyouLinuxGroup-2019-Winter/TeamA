/*************************************************************************
	> File Name: seqlist.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 01时04分55秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "SLT.h"
#include <string.h>
void SLTInit(SLT* SL)
{
    SL->len=0;
}
int SLTLength(SLT* SL)
{
    return (SL->len);
}
int SLTInsert(SLT* SL,int n,DATA data)
{
    int i;
    if(SL->len>=maxlen)
    {
        printf("顺序表已满，不能插入结点!\n");
        return 0;
    }
    if(n<1 || n>SL->len-1)
    {
        printf("插入元素序号错误，不能插入元素！\n");
        return 0;
    }
    for(i=SL->len;i>=n;i--)
        SL->ListData[i+1]=SL->ListData[i];

    SL->ListData[n]=data;
    SL->len++;
}
int SLTAdd(SLT* SL,DATA data)
{
    if(SL->len>=maxlen)
    {
        printf("顺序表已满！\n");
        return 0;
    }
    SL->ListData[++SL->ListData]=data;
}
int SLTDelete(SLT* SL,int n)
{
    int i;
    if(n<1 || n>SL->len+1)
    {
        printf("不能删除结点");
        return 0;
    }
    for(i=n;i<SL->len;i++)
        SL->ListData[i]=SL->ListData[i+1];

    SL->len--;
}

DATA* SLTFind_n(SLT* SL,int n)
{
    if(n<1 || n>SL->len+1)
    {
        printf("结点序号错误!\n");
        return NULL;
    }
    return &(SL->ListData[n]);
}
int SLTFind_key(SLT* SL,char* key)
{
    int i;
    for(i=0;i<=SL->len;i++)
    {
        if(strcmp(SL->ListData[i].key,key))
        {
            return i;
        }
    }
}

int SLTPrint(SLT* SL)
{
    int i;
    for(i=1;i<=SL->len;i++)
        printf("%s %s %d\n",SL->ListData[i].key,SL->ListData[i].name.SL->ListData[i].age);
}


