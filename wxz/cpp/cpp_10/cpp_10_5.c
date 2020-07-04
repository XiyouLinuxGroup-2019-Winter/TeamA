#include <stdio.h>
void value(double a[])
{
	double dvalue;
	double min=a[0];
	double max=a[0];
	int i;
	for(i=1;i<5;i++)
	{
		if(max<a[i])
			max=a[i];
		else if(min>a[i])
			min=a[i];
	}
	printf("%.2lf\n",max-min);

}
int main()
{
	double a[5]={1.2,3.4,5.6,7.8,1.4};
	value(a);
}
