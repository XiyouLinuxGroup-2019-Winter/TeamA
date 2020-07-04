#include <stdio.h>
void copy_arr(double (*source)[2],double (*target)[2],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		target[i][j]=source[i][j];
	}
}
int main()
{
	double source[5][2]={
		{1.1,2.2},
		{3.3,4.4},
		{5.5,6.6},
		{7.7,8.8},
		{9.9,10.1}
	};
	double target[5][2];
	copy_arr(source,target,10);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%lf ", target[i][j]);
	}
	printf("\n");
}
