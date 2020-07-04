/*************************************************************************
	> File Name: FactSum.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 01时08分59秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum(List L);

int main()
{
    int N,i;
    List L,p;

    scanf("%d",&N);
    L = NULL;
    for(i=0;i<N;i++ )
    {
        p=(List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next=L;
        L=p;
    }
    printf("%d\n",FactorialSum(L));

    return 0;
}
int FactorialSum(List L)
{
    int i;
    int n=1,sum=0;
    while(L!=NULL)
    {
        for(i=L->Data;i>0;i--)
            n=n*i;
        sum+=n;
        L=L->Next;
        n=1; 
    }
    return sum;
}
