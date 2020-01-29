#include<stdio.h>
int main()
{
    char*str=(char*)malloc(sizeof(char)*20);
    strcpy(str,"\0101\\xb2");
}