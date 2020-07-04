/*************************************************************************
	> File Name: joseph.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 08时44分53秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main()
{
    int m,i,cnt,j=1,k=0;
    int* p;
    printf("输入几个数:\n");
    scanf("%d",&cnt);
    printf("m=\n");
    scanf("%d",&m);
    p=(int*)malloc(cnt*sizeof(int));
    for(i=0;i<cnt;i++)
        p[i]=0;
    i=0;
    while(1)
    {
        if(i<cnt && 0==p[i])
        {
            if(m==j)
            {
                p[i]=1;
                j=0;
                printf("%d\t",i+1);
                k++;
                if(k==cnt)
                    break;
            }
            j++;
        }
        else if(i==cnt)
            i=-1;
        i++;
    }
    printf("\n");
}
/*typedef struct NODE{
    int data;
    int passwd;
    struct NODE* next;
}Node;
Node* create(int n);
Node* fun(Node* pre,int n);
void print(Node* head);
int main()
{

}*/
