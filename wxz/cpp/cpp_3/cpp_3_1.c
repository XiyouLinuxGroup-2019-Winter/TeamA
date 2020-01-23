#include <stdio.h>
int main()
{
	int a=2147483647;
	int b=-2147483647;
	unsigned int c=4294967295;
	unsigned int d=0;
	printf("%d %d %d\n",a,a+1,a+2);
	printf("%d %d %d\n",b,b-1,b-2);
	printf("%u %u %u\n",c,c+1,c+2);
	printf("%u %u %u\n",d,d-1,d-2);

	float toobig=3.4E38*100.0f;
	float toosmall=0.1234E-10/10.0;//1.4E-45/10.0
				       //1e-323/10.0;
	printf("%e %e\n",toobig,toosmall);
	printf("%f %f\n",toobig,toosmall);
	
}
