#include <stdio.h>
int Fib(int n)
{
	int i;
	int first=0;
	int second=1;
	int sum=0;
	for(i=0;i<n;i++)
	{
		if(i<2)
			printf("%d\n",i);
		sum=first+second;
		first=second;
		second=sum;
		printf("%d\n",sum);
	}
	return sum;


}
int main()
{
	int n=5;
	Fib(n);
}
