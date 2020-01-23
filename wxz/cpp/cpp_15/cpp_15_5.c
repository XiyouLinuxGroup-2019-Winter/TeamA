/*************************************************************************
	> File Name: cpp_15_5.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 12时21分46秒
 ************************************************************************/

#include<stdio.h>
int move(unsigned int n,unsigned int bit);
int main()
{
    unsigned int n,bit;
    while(scanf("%d %d",&n,&bit)==2)
    {
        printf("%d\n",move(n,bit));
    }
}
int move(unsigned int n,unsigned int bit)Zrintf(" %d ",pnew->data);
}
{
    int i=0;
    unsigned int high=8*sizeof(unsigned int);
    for(i=0;i<bit;i++)
    {
        if(n & (1<<(high-1)))
        n=(n<<1) | 1;
        else
        n=n<<1;
    }
    return n;
}
