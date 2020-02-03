#include <stdio.h>
#define ert 1.609
int main(void)
{
	double a,b,c,d,e,f;
	const double eat =3.875;
	scanf("%lf %lf",&a,&b);
	c=a*ert;
	e=a/b;
	d=b*eat;
	f=d/c*100;
	printf("加仑英里数:%.11f\n",e);
	printf("公里升数:%.11f\n",f);
	system("pause");
	return 0;		
}
