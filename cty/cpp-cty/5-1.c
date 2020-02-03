#include <stdio.h>
#define mt 60
int main(void)
{
	int fen,hour;
	printf("请输入:");
	while (1)
	{
	scanf("%d",&fen);
	if (fen<=0)
	{
	break;
	}
	if (fen>=60)
	{
	hour=fen/mt;
	}
	fen-=hour*mt;
	printf("%d小时%d分钟",hour,fen);
	}
return 0;
}

