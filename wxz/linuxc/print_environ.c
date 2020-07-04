/*************************************************************************
	> File Name: print_environ.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月10日 星期二 02时08分49秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    extern char **environ;
    int i;
    for(i=0; environ[i]!=NULL; i++)
    printf("%s\n", environ[i]);
}
