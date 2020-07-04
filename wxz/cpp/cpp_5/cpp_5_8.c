#include <stdio.h>
void Temperatures(double Fahrenheit)
{
	double Celsius, Kelvin;
	const double CE=1.8;
	const double US=32.0;
	const double KE=273.16;
	Celsius=Fahrenheit*CE+US;
	Kelvin=Celsius+KE;
	printf("%.2f\n",Celsius);
	printf("%.2f\n",Kelvin);
	printf("%.2f\n",Fahrenheit);
}
int main()
{
	double Fahrenheit;
	while(scanf("%f",&Fahrenheit)==1)
	Temperatures(Fahrenheit);
}
