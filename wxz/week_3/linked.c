/*************************************************************************
	> File Name: linked.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月01日 星期六 23时08分31秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    struct NODE* next;
    int data;
}Node;
Node* ReverNode(Node* head)
{
    if(head==NULL)
        return NULL;
    Node* pre=NULL;
    Node* temp=head;
    Node* p_temp=head;
}
int main()
{

}
