#include <stdio.h>
int main()
{
	int day;
	printf("请输入天数");
	scanf("%d",&day);
	printf("%d days is %d weeks,%d days",day,day/7,day%7);

}


