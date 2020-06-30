#include <stdio.h> 
#include <string.h>
#include "user_defined_3.h"
void menu();
int main()
{
	int n=0;
	Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		scanf("%d",&n);
		switch(n)
		{
			case ADD:
			AddContact(&con);
			break;
			case DEL:
			DelContact(&con);
			break;
			case SORT:
			break;
			case MODIFY:
			break;
			case SHOW:
			ShowContact(&con);
			break;
			case SEARCH:
			break;
			case EXIT:
			DestoryContact(&con);
			printf("退出程序\n");
			break;
			default:
			printf("选择错误\n");
			break;
		}
	}while(n);
}
void menu()
{
	printf("**********************************\n");
	printf("*********1.add         2.sum******\n");
	printf("*********3.mul         4.div******\n");
	printf("*********0.exit             ******\n");
	printf("**********************************\n");
}
