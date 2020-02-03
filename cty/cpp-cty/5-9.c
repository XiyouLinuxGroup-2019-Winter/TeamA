#include <stdio.h>

void Temperatures(double a);

int main(void)
{
double ft;
printf("请输入一个温度(华氏): ");

while (scanf("%lf", &ft) == 1)
{
Temperatures(ft);
printf("请输入一个温度 ( q to quit ) : ");
}
return 0;
}

void Temperatures(double a)
{
double ct;
double kt;
ct = 5.0 / 9.0 *(a - 32.0);
kt = ct + 273.16;
printf("%.2f华氏温度 = %.2f 摄氏温度 = %.2f 开氏温度\n", a, ct, kt);
}
