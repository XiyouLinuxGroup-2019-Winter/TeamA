/*************************************************************************
	> File Name: dfs.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 13时39分53秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <stdlbool.h>
bool judge(int x,int y);
void dfs(int x,int y,int step);
int 
void dfs(int x,int y,int step)
{
    //找到终点
    if(x=endx || y=endy)
        return;
    //遇到不能再走的点
    if(!judge(x,y))
        return;
}
bool judge(int x,int y)
{
    if(x<starx || x>endx || y<stary || y>endy)
        return false;
    return true;
}
