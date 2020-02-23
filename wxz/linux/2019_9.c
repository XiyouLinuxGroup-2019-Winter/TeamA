/*************************************************************************
	> File Name: 2019_9.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月17日 星期一 22时08分07秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    //char* q=p;
 	char *p = (char *)malloc(sizeof(char) * 20);
    char* q;
    //q=p;
    p=(char*)q;
 	scanf("%s %s", p, q);
 	printf("%s %s\n", p, q);
}
