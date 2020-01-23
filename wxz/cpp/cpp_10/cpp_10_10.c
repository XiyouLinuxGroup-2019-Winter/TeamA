#include <stdio.h>
void double_value(int arr[][5],int n);
void print(int arr[][5],int n);
int main()
{
	int a[3][5]={
		{1,2,3,4,5},
		{6,7,8,9,10},
		{2,3,4,5,6}
	};
	double_value(a,3);
	print(a,3);

}
void print(int arr[][5],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			printf("%d ",arr[i][j]);
			printf("\n");
}
void double_value(int arr[][5], int n)
{
	for (int i= 0;i<n; i++)
	for (int j= 0;j<5; j++)
		arr[i][j]*= 2;
}

