#include <stdio.h>
#define rows 5
void copy_arr(double source[],double arr[],int n);
void copy_ptr(double source[],double ptr[],int n);
void print(double arr[]);
int main()
{
	double source[5]={1.1,2.2,3.3,4.4,5.5};
	double target1 [5];
	double target2 [5];
	copy_arr(source,target1,5);
	copy_ptr(source,target1,5);
	print(target1);
	print(target2);
}
void copy_ptr(double sou[],double tar[],int n)
{
	int i;
	for(i=0;i<5;i++)
	*(tar+i)=*(sou+i);
}
void copy_arr(double sou[],double tar[],int n)
{
	int i;
	for(i=0;i<5;i++)
	tar[i]=sou[i];
	//*tar++=sou[i];
}
void print(double sou[])
{
	int i;
	for(i=0;i<5;i++)
	printf("%lf",sou[i]);
	printf("\n");
}



