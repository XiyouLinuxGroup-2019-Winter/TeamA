#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void GetMemory(char** p);
/*char* GetMemory(char* p);
void Test();

int main()
{
	Test();
	char* p="hello bit";
	printf("hello bit\n");
	printf(p);
	printf("%s\n",p);
	printf("hello bit\n");
}
void GetMemory(char** p) 
{
	*p = (char*)malloc(100);//临时变量p指向另一个动态开辟的空间的起始地址
} 
void Test() 
{ 
	char* str = NULL;//创建一个空指针str 
	GetMemory(&str); 
	strcpy(str,"hello world");//str还是一个空指针没有指向任何东西，空指针无法解引用
	printf(str);
	free(str);
	str=NULL;
}
//程序会崩溃，内存也会泄漏

//第二种改法
char* GetMemory(char* p)
{
	p=(char*)malloc(100);
	return p;
}
void Test()
{
	char* str=NULL;
	str=GetMemory(str);
	strcpy(str,"hello world");
	printf(str);
	free(str);
	str=NULL;
}

int *f1()
{
	int* ptr;//没有初始化，ptr是一个随机值，即随机地址
	*ptr=10;//一个随机地址解引用意思是随便找块空间，把10放进去，这个空间不一定是我们的(野指针)
	return ptr;
}*/

/*
char *GetMemory();
void Test();

int main()
{
	Test();
}
//返回栈空间地址的问题
char* GetMemory()
{
	char* p="hello world";//局部变量在栈上
	return p;//返回这个地址,这个数组的空间就不存在了
}
void Test()
{
	char* str=NULL;//
	str=GetMemory();//str指向的空间是NULL这个空间指向p数组
	printf(str);
}*/

//内存销毁：不是说这块空间不在了，它依然在内存里放着，只是说这块空间不属于我的当前程序了
/*int* test()
{
	int a=10;
	//返回栈空间地址的问题
	return &a;//test有一块空间，这块空间内容有a，a里面有10
}
//调用完这个函数后这块内存销毁
int main()
{
	int* p=test();//main函数有一块空间，这块空间内容有p，p指向a的那块空间，
	printf("hehe\n");//加上这个函数时，test函数已经调用过了，为printf函数开辟空间把test函数原先空间覆盖掉了
	printf("%d\n",*p);//test那块空间已经还给操作系统了，我们先为printf函数开辟空间
	//再调printf函数开辟空间，可能还是在原先上面开辟空间
	//如果不加的话*p的值可能是10也可能是随机值
}

void Test()
{
	char* str=(char*)malloc(100);
	strcpy(str,"hello");
	free(str);//当str开辟完后不为空指针，free完后把空间还给程序
	//非法访问内存
	str=NULL;

	if(str!=NULL)
	{
		strcpy(str,"world");
		printf(str);
	}
}
int main()
{
	Test();
}

//柔性数组
struct S2
{
	int num;
	int arr[0];//柔性数组成员
};*/

struct S
{
	int num;
	int arr[];//柔性数组成员
}

int main()
{
	pritnf("%d\n",sizeof(struct S));//
}





