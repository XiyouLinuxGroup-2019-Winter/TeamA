/*************************************************************************
	> File Name: 2017_4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 20时43分18秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
size_t q(size_t b)
{
    return b;
}
size_t(*p(char* str))(size_t a)
{
    printf("%s\n",str);
    return q;
}
int main()
{
    char str[]="XiyouLinuxGroup";
    printf("%lu\n",p(str)(strlen(str)));
}
