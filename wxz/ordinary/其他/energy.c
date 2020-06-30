#include <stdio.h>
int main()
{
	int a;
	float b;
	scanf("%d",&a);
	if(a<=150)
	b=0.4463*a;
	if(150<a<=400)
	b=0.4663*(a-150)+150*0.4463;
	if(a>400)
	b=0.5663*(a-400)+150*0.4463+250*0.4663;
	printf("%.1f\n",b);
}
