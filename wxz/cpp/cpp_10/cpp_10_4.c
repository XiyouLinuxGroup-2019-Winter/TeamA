#include <stdio.h>
void index_i(double a[])
{
	int i=0;
	int index=0;
	double max=a[0];
	for(i=1;i<5;i++)
	{
		if(max<a[i])
		index=i;
	}
		printf("%d\n",index);

}
int main()
{
	double a[5]={1.2,3.4,2.1,9.8,6.3};
	index_i(a);
}
