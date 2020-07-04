/*************************************************************************
	> File Name: 2018_8.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月16日 星期日 10时32分46秒
 ************************************************************************/

#include<stdio.h>
int f(unsigned int num)
{
    unsigned int i;
    printf( "%d\n",num);
    for(i = 0;num;i++)     
        num &= (num-1);        
        return i;
}
int main()
{
    printf("%d",f(2018));

}

