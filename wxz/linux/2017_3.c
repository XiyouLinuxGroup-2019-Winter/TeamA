/*************************************************************************
	> File Name: 2017_3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 20时37分57秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
/*void get_str(char **ptr)
{
    *ptr=(char*)malloc(17);
    strcpy(*ptr,"Xiyou Linux Group");
}


int main()
{
    char *str=NULL;
    get_str(&str);
    printf("%s\n",str);
}*/
void get_str(char* ptr)
{
    ptr=(char*)malloc(18);
    strcpy(ptr,"Xiyou Linux Group");
}
int main()
{
    char* str=NULL;
    str = (char*)malloc(18);
    strcpy(str, "xiyou linux group");
    printf("%s\n",str);
}
