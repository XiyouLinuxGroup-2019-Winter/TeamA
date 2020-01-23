#include <stdio.h>
void varr(int rows,int cols,double ar[rows][cols],double br[rows][cols]);
void print_varr(int rows,int cols,double ar[rows][cols]);
int main()
{
	double a[3][5]={
		{1.1,2.2,3.3,4.4,5.5},
		{6.6,7.7,8.8,9.9,10.1},
		{11.1,12.2,13.3,14.4,15.5}
		};
	double b[3][5];
	varr(3,5,a,b);
	print_varr(3,5,a);
	print_varr(3,5,b);
}
void varr(int rows,int cols,double ar[rows][cols],double b[rows][cols])
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
			b[i][j]=ar[i][j];
	}

}
void print_varr(int rows,int cols,double ar[rows][cols])
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
			printf("%lf",ar[i][j]);
	}
	printf("\n");
}
