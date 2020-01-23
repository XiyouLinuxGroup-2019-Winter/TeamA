#include <stdio.h>
void input(double (*a)[5],int n);
double aver(const double *a,int n);
void aver1(double (*a)[5],int n);
void max(double (*a)[5],int n);
void print(double (*a)[5],int n);
int main()
{
	double a[3][5];
	input(a,3);
	for(int i=0;i<3;i++)
	printf("%lf/n",aver(a[i],5));
	aver1(a,3);
	max(a,5);
	print(a,3);
}
void input(double (*a)[5],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			scanf("%lf",&a[i][j]);
}
double aver(const double *a;int n)
{
	double sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
		return sum/n;
}
void aver1(double (*a)[5],int n)
{
	int i,j;
	double sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
			sum+=a[i][j];
	}
	printf("%lf\n",sum/(n*5));
}
void max(double (*a)[5],int n)
{
	int i,j;
	double temp=a[0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
		if(temp<a[i][j])
			temp=a[i][j];
	}
	printf("%lf\n",temp);
}
void print(double (*a)[5],int n)
{
	int i, j;
	double max=a[0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
			printf("%lf",a[i][j]);
		printf("\n");
	}
}
