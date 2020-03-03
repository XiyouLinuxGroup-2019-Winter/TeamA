/*************************************************************************
	> File Name: test_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 01时08分36秒
 ************************************************************************/

#include<stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

/*typedef struct _Teacher{
    LinkListNode node;

    char name[32];
    int age;
}Teacher;*/

int main()
{
    void* list=NULL;
    Teacher t1,t2,t3,t4;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    t4.age=34;
    list=Create();
    if(list==NULL)
    {
        printf("链表创建失败！\n");
    }
    Insert(list,(LinkListNode *)&t1, 0);
	Insert(list,(LinkListNode *)&t2, 0);
	Insert(list,(LinkListNode *)&t3, 0);
    Insert(list,(LinkListNode *)&t4, 0);


    for(int i=0;i<Length(list);i++)
	{
		Teacher *t=(Teacher*)Get(list,i);
		if(NULL==t)
		{
			printf("获取结点失败\n");
		}
		printf("t->age:%d\n",t->age);
	}

    Destory(list);

}
