#include <stdio.h>
#define MONTHS 12
#define YEARS 5
void total(float a[][MONTHS], int n);		//五年总降水量
void sub(float a[][MONTHS], int n);		//每个月的平均降水量
int main()
{
	float rain[YEARS][MONTHS] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6 },
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3 },
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4 },
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2 },
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2 }
	};
	total(rain,YEARS);
	sub(rain,YEARS);
}
void total(float a[][MONTHS], int n)
{
	int i,j;
	float sum,total;
	for (i=0,total=0;i<n;i++)
	{
		for (j=0,sum= 0;j<MONTHS;j++)
			sum+=a[i][j];
		printf("%d   %.1f\n",2010+i,sum);
		total+=sum;
	}
	printf("%.1f\n",total/YEARS);
}
void sub(float a[][MONTHS],int n)
{
	int i,j;
	float total;
	for (i=0;i<MONTHS;i++)
	{
		for (j=0,total=0;j<n;j++)
			total += a[j][i];
		printf("%.1f\n",total/YEARS);
	}
}

