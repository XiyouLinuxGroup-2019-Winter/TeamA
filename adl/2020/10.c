#include<stdio.h>
int main(void)
{
/*	int a=128;
	int b=88;
	int c=129;
	int d=257;
	printf("%p\n",&a);
	printf("%p\n",(char*)&a);
		printf("%p\n",(char*)&b);
		printf("%p\n",(char*)&c);
		printf("%p\n",(char*)&d);
	
	printf("%d\n",*((char*)&a));
	printf("%d\n",*((char*)&b));
	printf("%d\n",*((char*)&c));
	printf("%d\n",*((char*)&d));
	return 0;*/
//	int a=129;
//	int b=2;
//	printf("%d\n%d\n",*((char*)&a),b);
//
typedef struct stu1{
   int m;
      int n;
 };
  typedef struct stu2{
     char c1;
     char c2;
 };
   struct stu1 s1;
    struct stu2 s2;
     s1.m = 815;  //11 00101111
     s1.n = 600;  
   s2 = *((struct stu2 *)&s1);
     printf("%d, %d, \n", s2.c1, s2.c2);
   int a = 559; //10 00101111
   char c = (char)a;
    printf("%d\n", c);
    s1.m = 559;
   s2 = *((struct stu2 *)&s1);
     printf("%d, %d, \n", s2.c1, s2.c2);
    return 0;
 }
 
