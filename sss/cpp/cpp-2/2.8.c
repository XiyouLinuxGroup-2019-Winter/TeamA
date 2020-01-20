#include <stdio.h>
void one();
void two();
int main()
{
	printf("starting now\n");
	one();
	two();
	printf("three\n");
	printf("done!\n");
}
void one()
{
	printf("one\n");
}
void two()
{
	printf("two\n");
}


