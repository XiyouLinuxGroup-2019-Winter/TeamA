#include <stdio.h>
float input()
{
	float a;
	char ch;
	while(scanf("%f",&a)!=1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);
		printf("is not an number\n");
		printf("please enter a number,such as 2.5,-1.78E8,or 3:");
	}
	return a;
}

void menu(void)
{
	printf("Enter the opration of your choice:\n");
	printf("a.add          s.subtract\n");
	printf("m.miltiply     d.divide\n");
	printf("q.quit\n");
}
int main()
{
	menu();
	char ch;
	float a,b;
	while((ch=getchar())!='q')
	{
		printf("\nEnter first number:");
		a=input();
		printf("Enter second number:");
		b=input();
		switch(ch)
		{
			case 'a':
			printf("%f",a+b);
			break;
			case 's':
			printf("%f",a-b);
			break;
			case 'm':
			printf("%f",a*b);
			break;
			case 'd':
			while(b==0.00)
			{
				printf("Enter a number other than 0:");
				b=input();
			}
			printf("%f",a/b);
			break;
			default:
			printf("please input a nmber again:");
			break;
		}
	}
	printf("Bye");
}
