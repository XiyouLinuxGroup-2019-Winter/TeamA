/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 09时37分48秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main()
{
    FILE* test;
    test=fopen("linux","w");
    if(test==NULL)
    {
        perror("data3");
        exit(EXIT_FAILURE);
    }
}
