#include<stdio.h>
void arr(double *,double *,int);
void ptr(double *,double *,int);
void ptrs(double *,double *,double *);
int main()
{
	double source[5]={1.1,2.2,3.3,4.4,5.5};
	double tar1[5],tar2[5],tar3[5];
	arr(tar1,source,5);
	ptr(tar2,source,5);
	ptrs(tar3,source,source+5);
	int i;
	for(i=0;i<5;i++)
	{
		printf("%lf %lf %lf\n",tar1[i],tar2[i],tar3[i]);
	}
}
void arr(double *tar,double *sour,int n)
{
	int i;
	for(i=0;i<n;i++)
		tar[i]=sour[i];
}
void ptr(double *tar,double *sour,int n)
{
	for(int i=0;i<n;i++)
		*(tar+i)=*(sour+i);
}
void ptrs(double *tar,double *sour,double*sours)
{
	while(sour<sours)
	{
		*tar=*sour;
		tar++;
		sour++;
	}
}


