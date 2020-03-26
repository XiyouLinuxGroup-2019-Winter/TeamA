/*************************************************************************
	> File Name: maze.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 23时43分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct num{
    int x;
    int y;
}maze;

maze a[25];
int cnt=0;
void way(int a[][7],int x,int y,int flag)
{
    a[cnt].x=x;
    a[cnt].y=y;
    cnt++;
    int i;
    if(x==4 && y==4)
    {
        for(i=0;i<cnt;i++)
            printf("(%d,%d)\n",a[i].x,a[i].y);
        exit(1);
    }
    if(a[x][y+1]==0 &&flag!=3)//右
        way(a,x,y+1,0);
    if(a[x+1][y]==0&& flag!=2)//下
        way(a,x+1,y,1);
    if(a[x-1][y]==0 && flag!=1)//上
        way(a,x-1,y,2);
    if(a[x][y-1]==0&&flag!=0)//左
        way(a,x,y-1,3);
    a[cnt].x=6;
    a[cnt].y=6;
    cnt--;
}
int main()
{
    int maze[7][7];
    int i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
            maze[i][j]=1;
    }
    for(i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			scanf("%d",&maze[i][j]);
    way(maze,0,0,0);
}
