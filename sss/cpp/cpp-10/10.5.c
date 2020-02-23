#include <stdio.h>
double asd(double *,int n);
int main()
{
	int n;
	scanf("%d",&n);
	double a[n];
	for(int i=0;i<n;i++)
		scanf("%lf",&a[i]);
	double h=asd(a,n);
	printf("%lf",h);
}
double asd(double *a,int n)
{
	double min=a[0],max=a[0];
	for(int i=1;i<n;i++)
	{
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	return max-min;
}



