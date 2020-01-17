/*************************************************************************
	> File Name: spiral_matrix.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 20时25分07秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    
    int value=0;
    int a[10][10];
    for(i=0;i<(n+1)/2;i++)
    {
        for(j=i;j<n-i;j++)
            a[i][j]=value++;//第一行，输出五个数
        for(j=i+1;j<n-i;j++)
            a[j][n-i-1]=value++;
        for(j=n-2-i;j>=i;j--)
            a[n-1-i][j]=value++;
        for(j=n-2-i;j>i;j--)
            a[j][i]=value++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
}
