/*************************************************************************
	> File Name: 2018.13.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月17日 星期一 00时20分30秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct a {
	char name[];
	int num;
} A;
A* func(A *a)
{
	a = (A *)malloc(sizeof(A));
	strcpy(a->name, "XiyouLinuxGroup");
	a->num= 2018;
    //return a;
}    
int main(int argc, char *argv[])
{
	A *a;
	a=func(a);
   // func(&a);
	printf("%s %d\n", a->name, a->num);
}
