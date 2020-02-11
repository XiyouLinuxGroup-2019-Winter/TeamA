#include <stdio.h>
int asd (double *,int n);
int main()
{
	int n;
	scanf("%d",&n);
	double a[n];
	for(int i=0;i<n;i++)
	scanf("%lf",&a[i]);
	int max=asd(a,n);
	printf("%d",max);
}
int asd (double *a,int n)
{
	int t=a[0],h;
	for(int i=1;i<n;i++)
	{
		if(t<a[i])
		{
			t=a[i];
			h=i;
		}
	}
	return h;
}


