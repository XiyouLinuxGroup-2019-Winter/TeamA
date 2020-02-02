#include <stdio.h>
   int main()
   {
           int hour;
	   char xuan,pan;
           float ji,gong,shui,jing;
	   printf("****************************************************************/n");
	   printf("Enter the numebr corresponding to the desired pay rate or action\n");
	   printf("(1) $8.75/hr          (2) $9.33/hr\n");
	   printf("(3) $10.00/hr         (4) $11.20/hr\n");
	   printf("(5) quit\n");
	   printf("****************************************************************\n");
	   printf("请选择基本工资\n");
	   scanf("%c",&xuan);
	   switch(xuan)
	   {
		   case '1' : ji=8.75;break;
		   case '2' : ji=9.33;break;
		   case '3' : ji=10.00;break;
		   case '4' : ji=11.20;break;
		   default : pan='/';break;
	   }
           while(pan=='/')
	   {
		   printf("清输入正确选项");
		   scanf("%c",&xuan);
		   switch(xuan)
             {
                     case '1' : ji=8.75;break;
                     case '2' : ji=9.33;break;
                     case '3' : ji=10.00;break;
                     case '4' : ji=11.20;break;
                     default : pan='/';break;
             }  
	   }
	   printf("请输入小时");
           scanf("%d",&hour);
           if(hour<=40)
                  gong=hour*ji;
           else
                  gong=40*ji+(hour-40)*1.5*ji;
          if(gong<=300)
                  shui=gong*0.15;
          else if(gong<=450&&gong>300)
                  shui=300*0.15+(gong-300)*0.2;
          else
                  shui=300*0.15+150*0.2+(gong-450)*0.25;
          jing=gong-shui;
          printf("gong=%g;shui=%g,jing=%g",gong,shui,jing);                             
  }

