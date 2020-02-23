#include <stdio.h>
void asd(double *,double *,int m,int n);
int main()
{
	double a[3][2]={
		         {1.1,2.2},
			 {3.3,4.4},
			 {5.5,6.6},
		        };
	double b[3][2];
	asd(a,b,3,2);
	for(int i=0;i<3;i++)
		for(int j=0;j<2;j++)
			printf("%lf",b[i][j]);
}
void asd(double (*a)[2],double (*b)[2],int m,int n)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			//b[i][j]=a[i][j];
	*(*(b+i)+j)=*(*(a+i)+j);
}




