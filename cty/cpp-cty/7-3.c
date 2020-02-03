#include<stdio.h>
int main(void)
{
int integer;
unsigned int e_number = 0;
unsigned int o_number = 0;
unsigned int e_sum = 0;
unsigned int o_sum = 0;
printf("Please enter some integer.(0 to quit)\n");
scanf("%d", &integer);
while (integer != 0)
{
if (integer % 2 == 0)
{
e_number++;
e_sum += integer;
}
else
{
o_number++;
o_sum += integer;
}
scanf("%d", &integer);
}
if (e_number == 0)
printf("The even number is 0 and the average even number is 0\n");
else
printf("The even number is %u and the average even number is %.2f\n",
e_number, (float)e_sum / e_number);
if (o_number == 0)
printf("The odd number is 0 and the average odd number is 0\n");
else
printf("The odd number is %u and the average odd number is %.2f\n",
o_number, (float)o_sum / o_number);
return 0;
}
