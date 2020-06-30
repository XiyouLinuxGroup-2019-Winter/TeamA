#include <stdio.h>
#include <stdlib.h>
int main()
{
	double* ptd;
	int max;
	int number;
	int i=0;
	printf("请输入你要的数字个数\n");
	scanf("%d",&max);
	ptd=(double*)malloc(max* sizeof(double));
	if(ptd== NULL)
		{
			printf("动态内存分配失败\n");
			exit(EXIT_FAILURE);
		}
	printf("请输入值\n");
	while(i<max && scanf("%lf",&ptd[i])==1)
		i++;
	printf("有%d个数\n",number=i);
	for(i=0;i<number;i++)
	{
		printf("%7.2f ",ptd[i]);
		if(i%7 !=0)
			printf("\n");
	}
	printf("完\n");
	free(ptd);
}
