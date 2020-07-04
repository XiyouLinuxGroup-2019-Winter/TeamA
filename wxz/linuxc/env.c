/*************************************************************************
	> File Name: env.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 02时38分44秒
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
extern char** environ;

int main(int argc,char* argv[])
{
    int i;
    printf("Argument:\n");
    for(i=0;i<argc;i++)
        printf("argv[%d] is %s\n",i,argv[i]);
    
    printf("Environment:\n");
    for(i=0;environ[i]!=NULL;i++)
        printf("%s\n",environ[i]);
}
