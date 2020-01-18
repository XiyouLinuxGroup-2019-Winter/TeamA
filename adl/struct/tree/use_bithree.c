#include<stdlib.h>
#include<stdio.h>
#include"bithrtree.h"

int main()
{
    BiThrTree B,T;
    CreatBiTree(&B);
    InOrderThreading(&T,B);
    printf("中序遍历结果是");
    InOrderTraverse_Thr(T);
    printf("\n");
    printf("中序遍历反向结果");
    REInOrderTraverse_Thr(T);
    printf("\n");

}