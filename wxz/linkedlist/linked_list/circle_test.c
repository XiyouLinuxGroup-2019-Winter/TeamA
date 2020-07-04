/*************************************************************************
	> File Name: circle_test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 23时44分51秒
 ************************************************************************/

#include<stdio.h>
#include "circle_list.h"
#include <stdlib.h>
typedef struct _tag_Teacher{
    CircleListNode head;
    int data;
}Teacher;
int main()
{
    int i=0;
    void* list=Create();
    //TCircleList* list=Create();
    Teacher v1,v2,v3,v4,v5,v6,v7,v8;

    v1.data=1;
    v2.data=2;
    v3.data=3;
    v4.data=4;
    v5.data=5;
    v6.data=6;
    v7.data=7;
    v8.data=8;

    Insert(list, (CircleListNode*)&v1, Length(list));
	Insert(list, (CircleListNode*)&v2, Length(list));
	Insert(list, (CircleListNode*)&v3, Length(list));
	Insert(list, (CircleListNode*)&v4, Length(list));
	Insert(list, (CircleListNode*)&v5, Length(list));
	Insert(list, (CircleListNode*)&v6, Length(list));
	Insert(list, (CircleListNode*)&v7, Length(list));
	Insert(list, (CircleListNode*)&v8, Length(list));

    for(i=0;i<Length(list);i++)
    {
        Teacher *pv=(Teacher*)SliderNext(list);
        printf("%d\n",pv->data);
    }
    printf("\n");

    SliderReset(list);

    while(Length(list)>0)
    {
        Teacher* pv=NULL;
        for(i=1;i<3;i++)
        {
            SliderNext(list);
        }
        pv=(Teacher*)SliderCurrent(list);
        printf("%d\n",pv->data);
        Delete_key(list,(CircleListNode*)pv);
    }
    Destroy(list);

}
