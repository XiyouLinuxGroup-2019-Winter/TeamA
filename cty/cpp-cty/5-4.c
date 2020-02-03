#include <stdio.h>
#define	feet 0.032808
#define feetinch 12
#define inch 0.3937008
int main(void)
{
	float heights,inchs;
	int feets;
	printf("请输入厘米数:");
	scanf("%f",&heights);
	while(heights>0)
	{
		feets=feet*heights;
		inchs=(heights*inch)-(feets*feetinch);
		printf("%.1fcm=%dfeet.%.1finches\n",heights,feets,inchs);
		printf("请再次输入:");
		scanf("%f",&heights);
	}	
return 0;
}
