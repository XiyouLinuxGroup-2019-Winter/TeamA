/*************************************************************************
	> File Name: 2019_8.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 00时40分55秒
 ************************************************************************/

#include<stdio.h>
/*int main()
{
    int val = 2018;
    int *pi = 2019;
    pi = &val;
    printf("%d\n",pi);
    *pi = 0;
    printf("%d\n",pi);
}*/
/*int main()
{
    unsigned char a=0;
    int c=a;
    int d=(int)a+1;
    printf("c= %d\n",c);
    printf("a=%c\n",a);
    printf("%d\n",d);
    
}*/
int main()
{
    int val=2018;
    int* p;
    *p=(int)2019;
    //int* p=2019;
    //int* p=(int*)2019;
    printf("%p\n %x\n",p,p);
    //p=&val;
    //*p=0;
    printf("p:%p\n",p);
    //printf("&val:%p  p:%p\n",&val,p);
    //printf("val:%d\n p:%d\n",val,p);
}
