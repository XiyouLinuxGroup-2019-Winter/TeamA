#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*int main()
{
	//要多大，就申请多大
	//-动态内存开辟
	//int* ptd=(int*)malloc(10*sizeof(int));
	int* ptd=(int*)malloc(10*sizeof(int));
	int i=0;
	if(ptd==NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	for(i=0;i<10;i++)
	{
		*(ptd+i)=i;
	}
	for(i=0;i<10;i++)
		printf("%d\n",*(ptd+i));
	free(ptd);//free完后ptd记得原来的地址
	ptd=NULL;
}*/

//栈区   局部变量，函数的形参
//堆区   动态内存开辟malloc,free,calloc,realloc
//静态区 全局变量，静态变量


//calloc开辟一个空间初始化0
/*int main()
{
	int* p=(int*)calloc(10,sizeof(int));
	int i=0;
	if(p=NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	for(i=0;i<10;i++)
	{
		*(p+i)=i;
	}
	for(i=0;i<10;i++)
		printf("%d\n",*(p+i));
	free(p);
	p=NULL;
}*/

int main()
{
	int* p=(int*)malloc(10*sizeof(int));
	int i=0;
	int* ptr=NULL;
	if(p=NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	for(i=0;i<10;i++)
		*(p+i)=i;
	//调整空间
	ptr=realloc(p,20*sizeof(int));
	if(ptr!=NULL)
		p=ptr;
	//for(i=0;i<10;i++)
	//	printf("%d\n",*(p+i));
	free(p);
	p=NULL;
}

int main()
{
	int* p=(int*)malloc(20*sizeof(int));
	if(p=NULL)
	{
		return 0;
	}
	*p=10;
	free(p);
	p=NULL;
}

int main()
{
	int i=0;
	int* p=malloc(10*sizeof(int));
	if(p=NULL)
		return 0;
	for(i=0;i<20;i++)
		printf("%d\n",*(p+i));
	free(p);
	p=NULL;
}

//对于非动态内存开辟
int main()
{
	int a=10;
	int* p=&a;

	free(p);
	p=NULL;
}

int main()
{
	int* p=(int*)malloc(40);
	if(p=NULL)
		return 0;
	for(int i=0;i<5;i++)
		*p++=i;
	free(p);
	p=NULL;
}
