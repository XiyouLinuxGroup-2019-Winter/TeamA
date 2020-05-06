/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 17时49分31秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"
typedef struct Teacher
{
    LinkListNode node;
    int age;
    char name[64];
}Teacher;
int main()
{
    int len=0;
    int ret=0;
    int i=0;

    LinkList* list=NULL;
    
    Teacher t1,t2,t3,t4,t5;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    t4.age=34;
    t5.age=35;

    list=LinkList_Create();
    if(list==NULL)
        return -1;

    len=LinkList_Length(list);

    ret=LinkList_Insert(list,(LinkListNode*)(&t1),0);
    ret=LinkList_Insert(list,(LinkListNode*)(&t2),0);
    ret=LinkList_Insert(list,(LinkListNode*)(&t3),0);
    ret=LinkList_Insert(list,(LinkListNode*)(&t4),0);
    ret=LinkList_Insert(list,(LinkListNode*)(&t5),0);

    //遍历
    for(i=0;i<LinkList_Length(list);i++)
    {
        Teacher* tmp=(Teacher*)LinkList_Get(list,i);
        if(tmp==NULL)
        {
            return -1;
        }
        printf("%d \n",tmp->age);
    }

    //删除链表
    while(LinkList_Length(list)>0)
    {
        /*Teacher* tmp=(Teacher*)LinkList_Delete(list,i);
        if(tmp==NULL)
        {
            return -1;
        }
        printf("%d \n",tmp->age);*/
        LinkList_Delete(list,0);
    }
    

    for(i=0;i<LinkList_Length(list);i++)
    {
        Teacher* tmp=(Teacher*)LinkList_Get(list,i);
        if(tmp==NULL)
        {
            return -1;
        }
        printf("%d \n",tmp->age);
    }
    LinkList_Destroy(list);
}
