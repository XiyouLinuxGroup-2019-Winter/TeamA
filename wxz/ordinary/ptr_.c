#include <stdio.h>
void test(int** p)
{
	printf("%d",**p);
}
int main()
{
	int *ptr=NULL;
	int *arr[10]={0};
	test(&ptr);
	test(arr);	
}
/*void Print(int (*p[5],int x,int y)
{
	int i=0;
	int j=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		printf("%d",(*(p+i)+j));
		printf("\n");
	}
	
}
void Print(int arr[3][5],int x,int y)
{
	int i=0;
	int j=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		printf("%d",arr[i][j]);
		printf("\n");
	}
}
int main()
{
	int arr[3][5]={1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};
	Print(arr,3,5);
	
}
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int (*p)[10]=&arr;
	int i=0;
	for(i=0;i<10;i++)
	printf("%d",(*p)[i]);
}
int main()
{
	int arr[10]={0};
	int* p=arr;
	p=&arr;
	printf("%p\n",arr);
	printf("%p\n",arr+1);
	
	printf("%p\n",&arr);
	printf("%p\n",&arr+1);
}
int main()
{
	int a=10;
	int *pa=&a;
	char ch='w';
	char *pc=&ch;
	int arr[10]={0};
	//数组指针
	int (*parr)[10]=&arr;
	
	char arr2[5];
	char (*parr2)[5]=&arr2;
	
	int *arr[10];
	int *(*p)[10]=&arr;
	int **p2=arr;	
}
int  main()
{
	char arr1[]="abcdef";
	char arr2[]="abcdef";
	if(arr1==arr2)
	printf("arr1==arr2\n");
	else
	printf("arr1!=arr2\n");
}

int main()
{
	char ch='w';
	char *pc=&ch;
	const char*p= "abcdef";
	char *p1="abcdef";
	char *p2="abcdef";
	
	return 0;
}*/
	

