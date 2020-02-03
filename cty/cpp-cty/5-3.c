#include <stdio.h>

int main(void)
{
	int day,week,newday;
	printf("请输入天数:");
	scanf("%d",&day);
	while (day>0)
	{
		week=day/7;
		newday=day%7;
		printf("%d days are %d weeks,%d days.\n",day,week,newday);
		printf("请再输入一个天数:");
		scanf("%d",&day);
	}		
return 0;
}
