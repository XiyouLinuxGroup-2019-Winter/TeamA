/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 03时28分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include "linkedlist.h"
void print(Node*  p)
{
    printf("%d\n", p->data); 
}
int main()
{
    Node* p = create(10);
    insert(p);
    p=create(5);
    insert(p);
    p= create(90);
    insert(p);
    p= search(5);
    delete(p);
    Free(p);
    traverse(print);
    destory();
    p= create(100);
    push(p);
    p= create(200);
    push(p);
    p= create(250);
    push(p);
    while (p = pop()) 
    {
        print(p);
        Free(p);
    }
}
