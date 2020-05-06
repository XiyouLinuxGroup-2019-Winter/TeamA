/*************************************************************************
	> File Name: test2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月04日 星期一 03时39分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "dlinklist.h"
struct Value
{
	DLinkListNode header;
	int v;
};

int main(int argc, char *argv[])
{
	DLinkList* list = DLinkList_Create();
	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	DLinkList_Insert(list, (DLinkListNode*)&v1, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v2, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v3, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v4, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v5, 0);

	DLinkList_Reset(list);
	//DLinkList_Pre(list);

	printf("%x\n", DLinkList_Current(list));

	DLinkList_Destroy(list);
	
}
