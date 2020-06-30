#include <stdio.h>
/*int main()
{
	int i=0;
	for(i=0;i<10;i++)
		printf("file:%s line:%d data:%s time:%s i=%d\n",__FILE__,__LINE__,__DATE__,__TIME__,i);
	printf("%s\n",__FUNCTION__);
	printf("%d\n",__STDC__);
}*/

/*#define MAX 1000
#define reg register
typedef register reg;
int main()
{
	register int age;
	reg int num;

}

#define PINT int*
typedef int* pint;
int main()
{
	PINT a;
	PINT b,c;//c是整型
	int *a,b;
	pint d,e;
}*/

/*
#define do_forever for(;;)
int main()
{
	do_forever
	{
		printf("hehe");
	}
}	
*/
/*
#define MAX 100;
int main()
{
	char* p="hello""bit\n";
	printf("hello"," bit");
	printf("%s\n",p);

}*/

/*
#define PRINT(FORMAT,VALUE)\printf("the value is "FORMAT\n",VALUE);
int main()
{
	PRINT("%d",10);
}*/
/*
#define MAX(X,Y) (X)>(Y)?(X):(Y)
int Max(int x,int y)
{
	return x>y?x:y;
}
int main()
{	
	int a=10;
	int b=20;
	int max=MAX(a++,b++);
	int max=((a++)>(b++)?(a++):(b++));
	printf("%d\n",max);

}*/

/*#define MAX 100
int main()
{
	printf("%d\n",MAX);
#undef
	printf("%d\n",MAX);
}*/
/*
int main()
{
#if 1
	printf("hehe\n");
#endif
}*/

/*
#define MAX 4
int main()
{
#if MAX==1
	printf("hehe\n");
#elif MAX==4
	printf("haha\n");
#else 
	printf("heihei\n");
#endif
}*/

#define MAX 100
/*int main()
{
#ifndef MAX
	printf("hehe\n");
#endif
}*/

int main()
{
	#if !defined(MAX)
	printf("hehe\n");
	#endif
}
