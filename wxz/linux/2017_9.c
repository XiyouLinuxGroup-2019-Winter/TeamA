/*************************************************************************
	> File Name: 2017_6.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月25日 星期六 20时49分36秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int a;
    int c=5;
    int b=2;
    for(a=1;a<4;a++)
    {
        switch(a)
        {
            printf("programme run here\n");
            b=99;
            case 2:
                printf("c is %d\n",c);
                break;
            default:
                printf("a is %d\n",a);
            case 1:
                printf("b is %d\n",b);
                break;
            //default:
                //printf("a is %d\n",a);
        }
    }
}
