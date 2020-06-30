/*************************************************************************
	> File Name: test3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月31日 星期五 23时10分17秒
 ************************************************************************/

#include<stdio.h>
struct str1
{
    char a;
    int b;
    float c;
    double d;
};
int main()
{
    printf("%d",sizeof(struct str1));
}
