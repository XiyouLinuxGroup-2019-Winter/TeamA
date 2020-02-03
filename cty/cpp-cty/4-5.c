#include <stdio.h>

int main(void)
{
	float a,b,t;
	printf("请输入下载速度:");
	scanf("%f",&a);
	printf("请输入文件大小:");
	scanf("%f",&b);
	t=((b*8)/a);	
	printf("At %0.2f megabits per second,a file of %0.2f megabytes\ndownloads in %0.2f seconds.",a,b,t);
	return 0;
}
