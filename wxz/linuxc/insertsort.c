/*************************************************************************
	> File Name: insertsort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 04时52分58秒
 ************************************************************************/

#include<stdio.h>
#define len 5
int a[len]={10,5,2,4,7};
void insertsort()
{
    int i,j,key;
    for(j=1;j<len;j++)
    {
        printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
}
int main()
{
    insertsort();
}
