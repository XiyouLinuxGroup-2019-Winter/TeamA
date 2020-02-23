/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月17日 星期一 23时03分54秒
 ************************************************************************/

#include<stdio.h>
enum Color

{

GREEN = 1,

RED,

BLUE,

GREEN_RED = 10,

GREEN_BLUE

}ColorVal;
int main()
{
    printf("%d",sizeof(ColorVal));
}
