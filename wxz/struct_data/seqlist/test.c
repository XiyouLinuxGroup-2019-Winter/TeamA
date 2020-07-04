/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月04日 星期一 14时38分39秒
 ************************************************************************/

#include<stdio.h>
#include"seqlist.h"
#include <stdlib.h>
typedef struct teacher
{
    int age;
    char name[64];
}Teacher;

int main()
{
    int ret,i;
    Teacher t1,t2,t3,t4,t5;
    SeqList* list;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    t4.age = 35;
    t5.age = 36;

    list=SeqList_Creat(10);
    if(list == NULL)
    {
        ret = -1;
        printf("func SeqList_Creat err:%d",ret);
        return -1;
    }
    
    Seqlist_Insert(list,(SeqListNode*)&t1,0); //头插法
    Seqlist_Insert(list,(SeqListNode*)&t2,0); //头插法
    Seqlist_Insert(list,(SeqListNode*)&t3,0); //头插法
    Seqlist_Insert(list,(SeqListNode*)&t4,0); //头插法
    Seqlist_Insert(list,(SeqListNode*)&t5,0); //头插法
    
    //printf("length = %d",SeqList_Length(list));
    //遍历
    for(i=0;i<SeqList_Length(list);i++)
    {
        Teacher *tmp=(Teacher *)SeqList_Get(list,i);
        if(tmp == NULL)
        {
            return -1;
        }
        printf("tmp->age:%d\n",tmp->age);
    }
    //删除元素
    while(SeqList_Length(list)>0)
    {
        Seqlist_Delete(list,0);
    }
    printf("length = %d\n",SeqList_Length(list));
    printf("capacity = %d\n",SeqList_Capacity(list));
}
