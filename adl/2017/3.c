#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void get(char**ptr)
{
    *ptr=(char*)malloc(18);
    strcpy(*ptr,"xiyou linux group");
        printf("%s",*ptr);
        printf("%p",*ptr);
}
int main()
{
    char *str=NULL;
    get(&str);

    printf("%p",str);
    printf("%s",str);
}