#include <stdio.h>
#define o 60;
int main()
{
	int i,j,h;
	printf("请输入分钟");
	while((scanf("%d",&i)==1)&&i>0)
	{
		j=i%o;
                h=i/o;
		printf("%d小时%d分\n",h,j);
		printf("请输入时间");
	}
}

		
