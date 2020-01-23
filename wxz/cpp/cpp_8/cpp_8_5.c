#include <stdio.h>
#include <ctype.h>
int main()
{
	int guess,start=1,end=100,ch;
	guess=50;
	printf("请选择一个1到100的数，我将尝试去猜一下");
	printf("如果我的答案是正确的，我将会回复Y");
	printf("如果猜错了会显示是偏大还是偏小");
	printf("%d",guess);
	while((ch=getchar())!='Y')
		{
			while(getchar()!='\n')
				continue;
			char result=getchar();
			if(result=='s')
			{
				guess=(guess+end)/2;
				printf("%d\n",guess);
				continue;
			}
			if(result='b')
			{
				guess=(guess+start)/2;
				printf("%d\n",guess);
				continue;
			}
		}
}

