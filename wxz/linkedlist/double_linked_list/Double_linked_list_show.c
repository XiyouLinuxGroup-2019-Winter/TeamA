/*************************************************************************
	> File Name: double_linked_list_show.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 00时57分23秒
 ************************************************************************/

#include<stdio.h>
#include "double_linked_list.h"
int main()
{
    Node* p;
    p=Create();
    Print(p);
    Insert(p);
    Print(p);
    Delete(p);
    Print(p);
    Destory(p);
}
