/*************************************************************************
	> File Name: 2019_6.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月16日 星期日 15时03分10秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
 	char x = -2, y = 3;
 	char t = (++x) | (y++);
 	printf("x = %d, y = %d, t = %d\n", x, y, t);
 	t= (++x) || (y++);
 	printf("x = %d, y = %d, t = %d\n", x, y, t);
 }
