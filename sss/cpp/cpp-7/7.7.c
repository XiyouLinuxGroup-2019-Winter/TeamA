#include <stdio.h>
int main()
{
	int hour;
	float gong,shui,jing;
        scanf("%d",&hour);
	if(hour<=40)
		gong=hour*10.00;
	else
		gong=40*10.00+(hour-40)*1.5*10.00;
	if(gong<=300)
		shui=gong*0.15;
	else if(gong<=450&&gong>300)
		shui=300*0.15+(gong-300)*0.2;
	else
		shui=300*0.15+150*0.2+(gong-450)*0.25;
	jing=gong-shui;
	printf("gong=%g;shui=%g,jing=%g",gong,shui,jing);
}

