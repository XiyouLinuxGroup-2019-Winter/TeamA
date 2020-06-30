#include <stdio.h>
//#include <stddef.h>
struct Stu
{
	char name[20];
	short age;
}s;
struct
{
	char name[20];
	short age;
}*ps;
int main()
{
	ps=&s;
}


//在声明结构体时，可以不完全声明
//匿名结构体变量

struct
{
	int a;
	char b;
	float c;
}x;
struct
{
	int a;
	char b;
	float c;
}a[20],*p;


struct Node
{
	int data;//4
	struct Node* next;//4
};


typedef struct Node
{
	int data;
	Node* next;
}Node;



struct Point
{
	int x;
	int y;
}p1;
struct Point p2;

struct Point p3={x,y};


#pragma pack(1)
#pragma pack(2)
struct A
{
	char c1;//1
	int a;//4
	char c2;//1
};
#pragma pack()
struct B
{
	char c1;//1
	char c2;//1
	int a;//4
};
struct S3
{
	double b;
	char c;
	int i;
};
struct S4
{
	char c1;
	struct S3 s3;
	double d;
};

int main()
{
	struct A sa={'a',20,'b'};
	printf("%d\n",sizeof(struct A));
	printf("%d\n",sizeof(struct B));
	printf("%d\n",sizeof(struct S3));
	printf("%d\n",sizeof(struct S4));
}

//百度面试题：
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出声明
#define OffSetOf(s,m) ((int)&(((s*)O)->m))   
struct S
{
	char c1;//0
	int a;//4
	char c2;//8
	//9-11
};
//offsetof()
int main()
{
	printf("%d\n",OffSetOf(struct S,c1));
	printf("%d\n",OffSetOf(struct S,a));
	printf("%d\n",OffSetOf(struct S,c2));
}
