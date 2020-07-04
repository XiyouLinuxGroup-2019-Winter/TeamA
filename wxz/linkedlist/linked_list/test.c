/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 17时15分42秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_list.h"
typedef struct _tag_Teacher{
    DLinkListNode node;
    int data;
}Teacher;
int main()
{
    int ret=0;
    void* list=NULL;
    Teacher t1,t2,t3,t4;
    t1.data=1;
    t2.data=2;
    t3.data=3;
    t4.data=4;

    list=Create();
    if(list==NULL)
    {
        ret=-1;
        printf("链表创建失败!\n");
        return ret;
    }

    //
    ret=Insert(list,(DLinkListNode*)&t1,Length(list));
    if(ret!=0)
    {
        ret=-2;
        printf("插入错误！\n");
        return ret;
    }
    ret=Insert(list,(DLinkListNode*)&t2,Length(list));
    ret=Insert(list,(DLinkListNode*)&t3,Length(list));
    ret=Insert(list,(DLinkListNode*)&t4,Length(list));

    int n=Length(list);
    printf("长度为：%d",ret);
    printf("\n=======================================\n");

    for(int i=0;i<Length(list);i++)
    {
        Teacher* tmp=(Teacher*)SliderNext(list);
        if(tmp==NULL)
        {
            ret=-3;
            printf("读取游标数据失败\n");
            return ret;
        }
        printf("%d",tmp->data);
    }

    printf("\n=======================================\n");


    for(int i=0;i<Length(list);i++)
    {
        Teacher* tmp=(Teacher*)Get(list,i);
        if(tmp==NULL)
        {
            ret=-4;
            printf("当前游标不存在!\n");
            return ret;
        }
        printf("%d",tmp->data);
    }
    printf("\n=======================================\n");

    
    //第一个数据
    Teacher* tmp1=(Teacher*)SliderReset(list);
    printf("%d ",tmp1->data);
    
    Teacher* tmp2=(Teacher*)SliderNext(list);
    printf("%d ",tmp2->data);

    tmp2=(Teacher*)Delete_i(list,1);
    printf("%d ",tmp2->data);

    tmp2=(Teacher*)SliderPre(list);
    printf("%d ",tmp2->data);

    Destroy(list);

    system("pause");
}
