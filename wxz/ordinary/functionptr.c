#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz-1;i++)
	{
		int j=0;
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}

	}
}
void Print_arr(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz;i++)
	printf("%d\n",arr[i]);
}
//void qsort
int com_int(const void* e1,const void* e2)
{		
	return *(int*)e1 -*(int*)e2;
	
	
}
int main()
{
	/*int a=10;
	float f=3.14f;
	void* pa=&a;
	pa=&f;*/
	int arr[]={3,1,5,2,4,7,9,6,8,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),com_int);
	bubble_sort(arr,sz);
	Print_arr(arr,sz);	
}
/*int main()
{
	int (*p)(int,int);//函数指针
	int(*parr[5])(int,int);//函数指针数组
	int (*(*pfarr[5]))=&parr;//pfarr指向函数指针数组的指针
}
*/
//函数指针数组的用途:转移表
/*void Calc(int(*pf)(int,int));
int Sub(int x,int y)
{
	return x-y;
}
int Add(int x,int y)
{
	return x+y;
}
int Mul(int x,int y)
{
	return x*y;
}
int Div(int x,int y)
{	
	return x/y;
}
void menu()
{
	printf("****************************\n");
	printf("*******   1.Add     2.Sub***\n");
	printf("*******   3.Mul     4.Div***\n");
	printf("*******   0.exit       *****\n");
	printf("****************************\n");

}
int main()
{
	int input;
	do
	{
		//int x=0;
		//int y=0;
		//int ret;
		//int(*pfarr[5])(int,int)={0,Add,Sub,Mul,Div};	

		menu();
		printf("请选择:>");
		scanf("%d",&input);
		
		switch(input)
		{
			case 1:
			Calc(Add);
			break;
			case 2:
			Calc(Sub);
			break;
			case 3:
			Calc(Mul);
			break;
			case 4:
			Calc(Div);
			break;
		}
		if(input>=1 &&input <=4)
	{
		printf("请输入两个操作数:>");
		scanf("%d%d",&x,&y);
		ret=pfarr[input](x,y);
		printf("ret=%d\n",ret);
	}
	else if(input==0)
	{		printf("退出\n");
		break;
	}
	else
		printf("选择错误\n");*/

		/*switch(input)
		{
			case 1:
				printf("请输入两个操作数:>");
				scanf("%d%d",&x,&y);
				ret=Add(x,y);
				printf("ret=%d\n",ret);
				break;
			case 2:
				printf("请输入两个操作数:>");
                                scanf("%d%d",&x,&y);
                                ret=Sub(x,y);
                                printf("ret=%d\n",ret);
				break;
			case 3:
				printf("请输入两个操作数:>");
                                scanf("%d%d",&x,&y);
                                ret=Mul(x,y);
                                printf("ret=%d\n",ret);
				break;
			case 4:
				printf("请输入两个操作数:>");
                                scanf("%d%d",&x,&y);
                                ret=Div(x,y);
                                printf("ret=%d\n",ret);
				break;
			case 0:
				printf("退出\n");
				break;
			default:
				printf("选择错误\n");	
				break;
		}
	}while(input);
}
void Calc(int(*pf)(int,int))
 {
         int x=0;
         int y=0;
         int ret=0;
         printf("请输入两个操作数:>");
         scanf("%d%d",&x,&y);
         //int(*pf[5])(int,int)={0,Add,Sub,Mul,Div};  
         ret=pf(x,y);
         printf("ret=%d\n",ret);
 }*/

/*int main()
{
	int (*p)(int,int);
	int (*parr[4])(int,int);				
	int (*(*pfarr)[4])=&parr;
}
int Add(int x,int y)
{
	return x+y;
}
int Sub(int x,int y)
{
	return x-y;
}
int main()
{
	int(*pa)(int,int)=Add;
	int(*ps)(int,int)=Sub;
 	//函数指针的数组
	int i=0;
	int (*pfarr[2])(int,int)={Add,Sub};
	for(i=0;i<2;i++)
	{
		int ret=pfarr[i](2,3);
		printf("%d\n",ret);
	}
	return 0;
}
int Add(int x,int y)
{
	return x+y;	
}
int main()
{
	int arr[10];
	printf("%d\n",&Add);
	printf("%p\n",Add);
	int(*pf)(int,int)=&Add;
	int ret=(******pf)(3,5);
	printf("%d\n",ret);
}*/
