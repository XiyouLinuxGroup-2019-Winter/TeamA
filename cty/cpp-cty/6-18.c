#include<stdio.h>
#define ORIGINAL 5
#define RATE 2
#define DUNBER 150
int main(void)
{
int weeks;
int friends = ORIGINAL;
for (weeks = 1; friends <= DUNBER; weeks++)
{
friends -= weeks;
friends *= 2;
printf("week= %d friend= %d\n", weeks, friends);
}
return 0;
}
