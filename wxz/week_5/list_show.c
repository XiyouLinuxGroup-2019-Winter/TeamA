/*************************************************************************
	> File Name: list_show.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 17时11分50秒
 ************************************************************************/

#include<stdio.h>
#include "list.h"
int main()
{
    LinkList* list = NULL;
    int ret,i;
    Teacher t1,t2,t3,t4,t5;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    t4.age = 34;
    t5.age = 35;
    list = LinkList_Creat();

    ret = LinkList_Insert(list,(LinkListNode *)(&t1),0);
    ret = LinkList_Insert(list,(LinkListNode *)(&t2),0);
    ret = LinkList_Insert(list,(LinkListNode *)(&t3),0);
    ret = LinkList_Insert(list,(LinkListNode *)(&t4),0);
    ret = LinkList_Insert(list,(LinkListNode *)(&t5),0);
    
    for(i = 0;i<LinkList_Length(list);i++)
    {
        Teacher *tmp = (Teacher *)LinkList_Get(list,i);
        if(tmp == NULL)
        {
            return 0;
        }
        printf("tmp->age:%d\n",tmp->age);
    }
    printf("length = %d\n",LinkList_Length(list));
    for(i = 0;i<4;i++)
    {
        LinkList_Delete(list,0);   
    }
    
    for(i = 0;i<LinkList_Length(list);i++)
    {
        Teacher *tmp = (Teacher *)LinkList_Get(list,i);
        if(tmp == NULL)
        {
            return 0;
        }
        printf("tmp->age:%d\n",tmp->age);
    }
    return 0;
}
