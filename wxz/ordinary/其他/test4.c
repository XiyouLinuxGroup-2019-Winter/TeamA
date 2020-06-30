/*************************************************************************
	> File Name: test4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 10时55分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
/*
void main()

{

int a=010,b=0x10,c=10;

printf("%d,%d,%d",a,b,c);

      }

*/
/*void main()
{
 int a=1234;
 printf("%2d\n",a);

}*/
/*void main()
{
 int a=0;
 a+=(a=8);
 printf("%x\n",a);

}*/
/*#include<stdio.h>

void main()

{

int a=30;

  printf("%d",(a/3>0)?a/10:a%3);

}*/
/*
#include<stdio.h>

void main()

{

    int n=0,m=1,x=2;

    if(!n) x-=1;

    if(m) x-=2;

    if(x)  x-=3;

    printf("%d\n",x);

}*/
/*void main()

{

    int p,a=5;

    if(p=a!=0)

       printf("%d\n",p);

    else

       printf("%d\n",p+2);

}*/
/*#include<stdio.h>

void main()

{

    int a=2,b=2,c;

    c=a==b;

    printf("c=%d\n",c);

}*/
/*#include<stdio.h>

int main()

{

      int  a = 2, b = -1, c = 2;

      if(a < b)

            if(b < 0)

                  c = 0;

      else  c++;

      printf("%d\n",c);

      return 0;

}

*/
#include <stdio.h>

void main()

{

int k=2;

switch(k)

{

case 1:printf("%d\n",k++);   break;

case 2:printf("%d ",k++);

case 3:printf("%d\n",k++);  break;

case 4:printf("%d\n",k++);

default:printf("Full!\n");

}

}
