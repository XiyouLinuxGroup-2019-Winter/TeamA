#include <stdio.h>
int asd(int *,int n);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int max=asd(a,n);
	printf("%d",max);

}
int asd(int *a,int n)
{
	int t=a[0];
	for(int i=1;i<n;i++)
	{
		if(t<a[i])
			t=a[i];
	}
	return t;
}

