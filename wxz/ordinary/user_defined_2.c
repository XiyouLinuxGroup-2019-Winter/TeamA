#include <stdio.h>
/*
struct S
{
	int _a:2;
	int _b:5;
	int _c:10;//17
	int _d:30;
};

int main()
{
	struct S s;
	//4-32
	//4
	printf("%d\n",sizeof(struct S));
}

struct S
{
	char a:3;
	char b:4;
	char c:5;
	char d:4;
};
int main()
{
	struct S s={0};
	s.a=10;
	s.b=12;
	s.c=3;
	s.d=4;
}
//1010
*/

/*enum Sex
{
	MALE,
	FEMALE,
	SECRET
};

int main()
{
	enum Sex sex=SECRET;
	printf("%d\n",MALE);
	printf("%d\n",FEMALE);
	printf("%d\n",SECRET);
}

void menu()
{
	printf("**********************************\n");
	printf("*********1.add         2.sum******\n");
	printf("*********3.mul         4.div******\n");
	printf("*********0.exit             ******\n");
	printf("**********************************\n");
}*/
/*
enum Option
{
	EXIT,
	ADD,
	SUM,
	MUL,
	DIV
};
int main()
{
	int n;
	do
	{
		//menu();
		scanf("%d",&n);
		switch(n)
		{
			case ADD:
			break;
			case SUM:
			break;
			case MUL:
			break;
			case DIV:
			break;
			case EXIT:
			break;
		}
	}while();
}*/

//联合体也叫共用体，共用一块空间
/*
union U
{
	char c[5];
	int i;
	
};

int main()
{
	union U u;
	printf("%d\n",sizeof(u));
	printf("%p\n",&u);
	printf("%p\n",&(u.c));
	printf("%p\n",&(u.i));
	
}*/
int check_sys()
{
	//匿名共用体
	union
	{
		char c;
		int i;
	}u;
	u.i=1;
	return u.c;
	//返回1，表示小端
	//返回0，表示大端
	//int a=1;
	//return *(char*)&a;
}
int main()
{
	int ret=check_sys();
	if(1==ret)
		printf("小端\n");
		else
			printf("大端\n");
	int a=1;
	//00 00 00 01
	//01 00 00 00 小端
	//00 00 00 01 大端
}

