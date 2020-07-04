/*************************************************************************
	> File Name: double_linked_list.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 00时33分05秒
 ************************************************************************/

#include<stdio.h>
typedef struct NODE{
    struct NODE* fwd;
    struct NODE* bwd;
    int     value;
}Node;

