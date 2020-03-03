/*************************************************************************
	> File Name: maze.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 15时02分41秒
 ************************************************************************/

#include "maze.h"
#include <stdio.h>
int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};
void print_maze(void)
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++) 
    {
        for (j = 0; j < MAX_COL; j++)
        printf("%d ", maze[i][j]);    
        putchar('\n');
    }
 printf("*********\n");
}
/*#include<stdio.h>
int maze[5][5]={
    0,1,0,0,0,
    0,1,0,1,0,
    0,0,0,0,0,
    0,1,1,1,0,
    0,0,0,1,0,
};
#define max_row 5
#define max_col 5

struct Stack{
    int row;
    int col;
}stack[512];

int top=0;
void push(struct Stack p);
struct Stack pop();
int is_empty();
void print();
void visit(int row,int col,struct Stack pre);

int main()


void push(struct Stack  p)
{
    stack[top++]=p;
}
struct Stack pop()
{
    return stack[--top];
}
int is_empty()
{
    return top==0;
}
void print()
{
    int i,j;
    for(i=0;i<max_row;i++)
    {
        for(j=0;j<max_col;j++)
            printf("%d ",maze[i][j]);
        putchar('\n');
    }
    printf("**********\n");
}
struct Stack prede[max_row][max_col]={
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
};
void visit(int row,int col,struct Stack pre)
{
    struct Stack visit={row,col};
    maze[row][col]=2;
    prede[row][col]=pre;
    push(visit);
}
*/
