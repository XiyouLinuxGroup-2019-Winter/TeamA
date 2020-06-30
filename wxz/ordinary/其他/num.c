#include <stdio.h>
int count_one_bits(unsigned int n)
{
	int count=0;
	while(n)
	{
		if(n%2==1)
		count++;
		n/=2;
	}
	return count;
}
int main()
{
	int num=-1;
	int ret=count_one_bits(num);
	printf("%d\n",ret);
}
