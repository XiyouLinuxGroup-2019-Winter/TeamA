#include <stdio.h>
int main()
{
	double su,um;
	int i,j;
	su=100.0;
	um=100.0;
	for(i=1; ;i++)
	{
		su=100.0+i*10.0;
		um=um*1.05;
		if(um>su)
			break;
	}
	printf("第%d年\n",i);
	printf("Deirdre的余额:%f,Daphne的余额:%f",su,um);
}




